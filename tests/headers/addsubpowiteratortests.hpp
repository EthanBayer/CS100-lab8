#ifndef ADDSUBPOWITERATORTESTS_HPP
#define ADDSUBPOWITERATORTESTS_HPP

#include <gtest/gtest.h>
#include "../../headers/iterator.hpp"
#include "../../compositeclasses/base.hpp"
#include "../../compositeclasses/Add.hpp"
#include "../../compositeclasses/Op.hpp"
#include "../../compositeclasses/Sub.hpp"
#include "../../compositeclasses/Pow.hpp"
#include "../../compositeclasses/Mult.hpp"
#include "../../compositeclasses/Div.hpp"
#include <vector>

TEST(AddSubPowIteratorTests, AddTest)
{
    std::vector<double> testValues = { 3, 1, 2, 3 };
    int size = 0;
    Op* one = new Op(1.00);
    Op* two = new Op(2.00);
    Add* tree1 = new Add(one, two);
    
    PreorderIterator* pi = new PreorderIterator(tree1);
    pi->first();
    while(!pi->is_done())
    {
        size++;
        pi->next();
    }

    //it is equal to 2 since it skips first root node
    ASSERT_TRUE(size == 2);

    Op* three = new Op(3.00);
    Add* tree2 = new Add(tree1, three);

    size = 0;
    pi = new PreorderIterator(tree2);
    pi->first();
    while(!pi->is_done())
    {
        size++;
        pi->next();
    }

    ASSERT_TRUE(size == 4);

    int i = 0;
    while(!pi->is_done())
    {
        ASSERT_EQ(pi->current()->evaluate(), testValues.at(i));
        i++;
        pi->next();
    }
}

TEST(AddSubPowIteratorTests, SubTest)
{
    std::vector<double> testValues = { 1, 2, 1, 3 };
    int size = 0;
    Op* one = new Op(1.00);
    Op* two = new Op(2.00);
    Sub* tree1 = new Sub(two, one);
    
    PreorderIterator* pi = new PreorderIterator(tree1);
    pi->first();
    while(!pi->is_done())
    {
        size++;
        pi->next();
    }

    //it is equal to 2 since it skips first root node
    ASSERT_TRUE(size == 2);

    Op* three = new Op(3.00);
    Sub* tree2 = new Sub(three, tree1);

    size = 0;
    pi = new PreorderIterator(tree2);
    pi->first();
    while(!pi->is_done())
    {
        size++;
        pi->next();
    }

    ASSERT_TRUE(size == 4);

    int i = 0;
    while(!pi->is_done())
    {
        ASSERT_EQ(pi->current()->evaluate(), testValues.at(i));
        i++;
        pi->next();
    }
}

TEST(AddSubPowIteratorTests, PowTest)
{
    std::vector<double> testValues = { 2, 2, 1, 3 };
    int size = 0;
    Op* one = new Op(1.00);
    Op* two = new Op(2.00);
    Pow* tree1 = new Pow(two, one);
    
    PreorderIterator* pi = new PreorderIterator(tree1);
    pi->first();
    while(!pi->is_done())
    {
        size++;
        pi->next();
    }

    //it is equal to 2 since it skips first root node
    ASSERT_TRUE(size == 2);

    Op* three = new Op(3.00);
    Pow* tree2 = new Pow(three, tree1);

    size = 0;
    pi = new PreorderIterator(tree2);
    pi->first();
    while(!pi->is_done())
    {
        size++;
        pi->next();
    }

    ASSERT_TRUE(size == 4);

    int i = 0;
    while(!pi->is_done())
    {
        ASSERT_EQ(pi->current()->evaluate(), testValues.at(i));
        i++;
        pi->next();
    }
}

TEST(AddSubPowIteratorTests, MultTest)
{
    std::vector<double> testValues = { 2, 2, 1, 3 };
    int size = 0;
    Op* one = new Op(1.00);
    Op* two = new Op(2.00);
    Mult* tree1 = new Mult(two, one);
    
    PreorderIterator* pi = new PreorderIterator(tree1);
    pi->first();
    while(!pi->is_done())
    {
        size++;
        pi->next();
    }

    //it is equal to 2 since it skips first root node
    ASSERT_TRUE(size == 2);

    Op* three = new Op(3.00);
    Mult* tree2 = new Mult(three, tree1);

    size = 0;
    pi = new PreorderIterator(tree2);
    pi->first();
    while(!pi->is_done())
    {
        size++;
        pi->next();
    }

    ASSERT_TRUE(size == 4);

    int i = 0;
    while(!pi->is_done())
    {
        ASSERT_EQ(pi->current()->evaluate(), testValues.at(i));
        i++;
        pi->next();
    }
}

TEST(AddSubPowIteratorTests, DivTest)
{
    std::vector<double> testValues = { 2, 2, 1, 3 };
    int size = 0;
    Op* one = new Op(1.00);
    Op* two = new Op(2.00);
    Div* tree1 = new Div(two, one);
    
    PreorderIterator* pi = new PreorderIterator(tree1);
    pi->first();
    while(!pi->is_done())
    {
        size++;
        pi->next();
    }

    //it is equal to 2 since it skips first root node
    ASSERT_TRUE(size == 2);

    Op* three = new Op(3.00);
    Div* tree2 = new Div(three, tree1);

    size = 0;
    pi = new PreorderIterator(tree2);
    pi->first();
    while(!pi->is_done())
    {
        size++;
        pi->next();
    }

    ASSERT_TRUE(size == 4);

    int i = 0;
    while(!pi->is_done())
    {
        ASSERT_EQ(pi->current()->evaluate(), testValues.at(i));
        i++;
        pi->next();
    }
}

#endif