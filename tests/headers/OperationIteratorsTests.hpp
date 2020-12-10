#pragma once

#include<gtest/gtest.h>
#include "../../headers/iterator.hpp"
#include "../../compositeclasses/Op.hpp"
#include "../../compositeclasses/Rand.hpp"
#include "../../compositeclasses/Mult.hpp"
#include "../../compositeclasses/Div.hpp"
#include "../../compositeclasses/Add.hpp"
#include "../../compositeclasses/Sub.hpp"
#include "../../compositeclasses/Pow.hpp"


class OperationIteratorTest : public ::testing::Test{
public:
    Base* operation;
    ~OperationIteratorTest(){
        delete operation;
    }
};

//============== Tests for Op and Rand ================================
/*
This classes are tesed separately because their get_left/right functions are
void and do nothing. Hence each must be tested separately to check that nothing changed
when those functions were called.
*/

TEST_F(OperationIteratorTest, OpCreateIterTest){
    operation = new Op(8);
    auto iter = operation->create_iterator();
    EXPECT_EQ(iter->is_done(), true);
    EXPECT_EQ(iter->current(), nullptr);
}

TEST_F(OperationIteratorTest, RandCreateIterTest){        
    operation = new Rand;
    auto iter = operation->create_iterator();
    EXPECT_EQ(iter->is_done(), true);
    EXPECT_EQ(iter->current(), nullptr);
}

TEST_F(OperationIteratorTest, OpGetLeftRightTest){
    operation = new Op(8);

    EXPECT_EQ(operation->get_left(), nullptr);
    EXPECT_EQ(operation->get_right(), nullptr);
}

TEST_F(OperationIteratorTest, RandGetLeftRightTest){
    operation = new Rand;

    EXPECT_EQ(operation->get_left(), nullptr);
    EXPECT_EQ(operation->get_right(), nullptr);
}

//================== Parametrized test for get_left() and get_right() functions. =============================
struct input{
    Base * op;
    double exp_left;
    double exp_right;
};


class GetLeftRightTest: public OperationIteratorTest,
public ::testing::WithParamInterface<input>{};

TEST_P(GetLeftRightTest, getLeftTest){
    operation = GetParam().op;
    
    EXPECT_EQ(operation->get_left()->evaluate(), GetParam().exp_left);
}

TEST_P(GetLeftRightTest, getRightTest){
    operation = GetParam().op;

    EXPECT_EQ(operation->get_right()->evaluate(), GetParam().exp_right);
}

INSTANTIATE_TEST_SUITE_P(LeftRightGetters, GetLeftRightTest,
    ::testing::Values(
        input({new Mult(new Op(3), new Op(4)), 3, 4}),
        input({new Div(new Op(18), new Op(6)), 18, 6}),
        input({new Add(new Op(6), new Op(9)), 6, 9}),
        input({new Sub(new Op(1), new Op(0)), 1, 0}),
        input({new Pow(new Op(56), new Op(6)), 56, 6})
    )
);

//=============== Parametrized for testing for create_iterator() on binary operations ==============================

class ParametrizedBinaryOperationIteratorTests:
 public OperationIteratorTest,
  public ::testing::WithParamInterface<Base*>{};

TEST_P(ParametrizedBinaryOperationIteratorTests, CreateIterTest){
    operation = GetParam();
    auto iter = operation->create_iterator();

    ASSERT_EQ(iter->is_done(), false);

    EXPECT_EQ(iter->current()->evaluate(), operation->get_left()->evaluate());
}

TEST_P(ParametrizedBinaryOperationIteratorTests, FirstFunctionTest){
    operation = GetParam();

    auto iter = operation->create_iterator();

    iter->first();

    ASSERT_EQ(iter->is_done(), false);

    EXPECT_EQ(iter->current()->evaluate(), operation->get_left()->evaluate());
}

TEST_P(ParametrizedBinaryOperationIteratorTests, NextFunctionTest){
    operation = GetParam();

    auto iter = operation->create_iterator();

    iter->next();

    ASSERT_EQ(iter->is_done(), false);

    EXPECT_EQ(iter->current()->evaluate(), operation->get_right()->evaluate());
}

TEST_P(ParametrizedBinaryOperationIteratorTests, IsDoneFunctionTest){
    operation = GetParam();

    auto iter = operation->create_iterator();

    iter->next();
    iter->next();

    ASSERT_EQ(iter->is_done(), true);
    EXPECT_EQ(iter->current(), nullptr);
}


INSTANTIATE_TEST_SUITE_P(BinaryOperations, ParametrizedBinaryOperationIteratorTests,
    testing::Values(
        new Mult(new Op(7), new Op(4)),
        new Div(new Op(12), new Op(3)),
        new Add(new Op(12), new Op(3)),
        new Sub(new Op(12), new Op(3)),
        new Pow(new Op(12), new Op(3))
    )
);

//====================== Pre-order iterator =====================================

/*
This test is based on a single instance of a preorder iterator. To improve it in the
future, I suggest making it parametrized and include many preorder iterators as values. 
*/

class PreOrderIteratorTests: public ::testing::Test{
public:

    PreorderIterator* preIter;
    Base* expression;

    PreOrderIteratorTests(){
        expression = new Mult(
            new Mult(
                new Div(new Op(36), new Op(18)),
                new Mult(new Op(2), new Op(3))
            ),
            new Div(
                new Mult(new Op(5),new Op(7)),
                new Op(5)
                )
        );

        preIter = new PreorderIterator(expression);
    }
    ~PreOrderIteratorTests(){
        delete expression;
        delete preIter;
    }
};

TEST_F(PreOrderIteratorTests, PreOrderFirstTest){
    preIter->first();

    double preIterResult = 12; // (36/18) * (2*3) which is the first left node of the tree.

    ASSERT_EQ(preIter->current()->evaluate(), preIterResult);

    for(int i = 0; i < 3; i++){
        preIter->next();
    }

    preIterResult = 18; //expected result after calling next 3 times.

    EXPECT_TRUE(preIter->current()->evaluate() == preIterResult);

    preIter->first();

    preIter->first();

    preIterResult = 12; // (36/18) * (2*3) which is the first left node of the tree.

    ASSERT_EQ(preIter->current()->evaluate(), preIterResult);
}

TEST_F(PreOrderIteratorTests, PreOrderNextTest){
    std::vector<double> expected_results({12, 2, 36, 18, 6, 2, 3, 7, 35, 5, 7, 5}); //Values expected at each node, starting with first left node, for this specific expression.


    preIter->first();
    int i = 0;
    while(!preIter->is_done()){
        EXPECT_EQ(preIter->current()->evaluate(), expected_results[i++]);
        preIter->next();
    }
}

TEST_F(PreOrderIteratorTests, PreOrderCurrent){
    preIter->first();

    std::vector<double> expected_results({12, 2, 36, 18, 6, 2, 3, 7, 35, 5, 7, 5}); //For this test fixture

    EXPECT_EQ(preIter->current()->evaluate(), expected_results[0]);

    preIter->next();
    preIter->next();
    preIter->next();
    preIter->next();

    EXPECT_EQ(preIter->current()->evaluate(), expected_results[4]);
}

TEST_F(PreOrderIteratorTests, PreOrderIsDoneTest){
    int i = 0;
    preIter->first();
    while(!preIter->is_done()){
        i++;
        preIter->next();
    }
    //First operation is not counted so the iterator should be done after 12 calls to next();
    EXPECT_EQ(i, 12);
    
}
