#ifndef ADDSUBPOWVISITORTESTS_HPP
#define ADDSUBPOWVISITORTESTS_HPP

#include <gtest/gtest.h>
#include "../../headers/iterator.hpp"
#include "../../headers/visitor.hpp"
#include "../../compositeclasses/base.hpp"
#include "../../compositeclasses/Add.hpp"
#include "../../compositeclasses/Op.hpp"
#include "../../compositeclasses/Sub.hpp"
#include "../../compositeclasses/Pow.hpp"
#include "../../compositeclasses/Mult.hpp"
#include "../../compositeclasses/Div.hpp"

TEST(VisitorTests, Test1)
{
    CountVisitor* cv = new CountVisitor();

    Op* one = new Op(1);
    Op* two = new Op(2);
    Add* tree1 = new Add(one, two);
    Op* three = new Op(3);
    Sub* tree2 = new Sub(three, tree1);
    Pow* tree3 = new Pow(two, tree2);
    Add* dummyhead = new Add(tree3, one);

    PreorderIterator* pi = new PreorderIterator(dummyhead);
    pi->first();
    while(!pi->is_done())
    {
        pi->current()->accept(cv);
        pi->next();
    }

    EXPECT_EQ(cv->op_count(), 5);
    EXPECT_EQ(cv->pow_count(), 1);
    EXPECT_EQ(cv->add_count(), 1);
    EXPECT_EQ(cv->sub_count(), 1);
}

TEST(VisitorTests, Test2)
{
    CountVisitor* cv = new CountVisitor();

    Op* one = new Op(1);
    Op* two = new Op(2);
    Add* tree1 = new Add(one, two);
    Op* three = new Op(3);
    Sub* tree2 = new Sub(three, tree1);
    Pow* tree3 = new Pow(two, tree2);
    Op* four = new Op(4);
    Add* tree4 = new Add(four, tree3);
    Sub* tree5 = new Sub(tree4, three);
    Add* dummyhead = new Add(tree5, one);

    PreorderIterator* pi = new PreorderIterator(dummyhead);
    pi->first();
    while(!pi->is_done())
    {
        pi->current()->accept(cv);
        pi->next();
    }

    EXPECT_EQ(cv->op_count(), 7);
    EXPECT_EQ(cv->pow_count(), 1);
    EXPECT_EQ(cv->add_count(), 2);
    EXPECT_EQ(cv->sub_count(), 2);
}

TEST(VisitorTests, Test3)
{
    CountVisitor* cv = new CountVisitor();

    Op* one = new Op(1);
    Op* two = new Op(2);
    Add* tree1 = new Add(one, two);
    Op* three = new Op(3);
    Sub* tree2 = new Sub(three, tree1);
    Pow* tree3 = new Pow(two, tree2);
    Op* four = new Op(4);
    Add* tree4 = new Add(four, tree3);
    Sub* tree5 = new Sub(tree4, three);
    Add* tree6 = new Add(tree5, four);
    Add* tree7 = new Add(tree6, three);
    Pow* tree8 = new Pow(tree7, one);
    Add* dummyhead = new Add(tree8, one);

    PreorderIterator* pi = new PreorderIterator(dummyhead);
    pi->first();
    while(!pi->is_done())
    {
        pi->current()->accept(cv);
        pi->next();
    }

    EXPECT_EQ(cv->op_count(), 10);
    EXPECT_EQ(cv->pow_count(), 2);
    EXPECT_EQ(cv->add_count(), 4);
    EXPECT_EQ(cv->sub_count(), 2);
}

TEST(VisitorTests, Test4)
{
    CountVisitor* cv = new CountVisitor();

    Op* one = new Op(1);
    Op* two = new Op(2);
    Add* tree1 = new Add(one, two);
    Op* three = new Op(3);
    Div* tree2 = new Div(three, tree1);
    Pow* tree3 = new Pow(two, tree2);
    Op* four = new Op(4);
    Add* tree4 = new Add(four, tree3);
    Sub* tree5 = new Sub(tree4, three);
    Mult* tree6 = new Mult(tree5, four);
    Add* tree7 = new Add(tree6, three);
    Pow* tree8 = new Pow(tree7, one);
    Add* dummyhead = new Add(tree8, one);

    PreorderIterator* pi = new PreorderIterator(dummyhead);
    pi->first();
    while(!pi->is_done())
    {
        pi->current()->accept(cv);
        pi->next();
    }

    EXPECT_EQ(cv->op_count(), 10);
    EXPECT_EQ(cv->pow_count(), 2);
    EXPECT_EQ(cv->add_count(), 3);
    EXPECT_EQ(cv->sub_count(), 1);
    EXPECT_EQ(cv->mult_count(), 1);
    EXPECT_EQ(cv->div_count(), 1);
}

#endif