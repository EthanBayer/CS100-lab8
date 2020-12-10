#include <gtest/gtest.h>

#include "headers/addsubpowiteratortests.hpp"
#include "headers/addsubpowvisitortests.hpp"
#include "headers/OperationIteratorsTests.hpp"



int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
