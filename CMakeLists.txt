CMAKE_MINIMUM_REQUIRED(VERSION 2.8.12)

ADD_SUBDIRECTORY(googletest)

SET(CMAKE_CXX_STANDARD 11)

INCLUDE_DIRECTORIES(googletest/include)

ADD_EXECUTABLE( test
    tests/unit_test.cpp
    src/binary_iterator.cpp
    src/preorder_iterator.cpp
    src/visitor.cpp
    src/binary_iterator.cpp
)


ADD_EXECUTABLE(example
    tests/main.cpp
    src/binary_iterator.cpp
    src/preorder_iterator.cpp
    src/visitor.cpp
)


TARGET_LINK_LIBRARIES(test gtest)
TARGET_COMPILE_DEFINITIONS(test PRIVATE gtest_disable_pthreads=ON)
