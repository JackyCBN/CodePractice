#include "gtest/gtest.h"
#include "sort/bubbleSort.h"

TEST(bubleSortTest, test1) {
    int t[]  = {
        2,
        3,
        1
    };
    bubblesort(t,3);
    EXPECT_EQ (t[0], 1);
    EXPECT_EQ (t[1], 2);
    EXPECT_EQ (t[2], 3);
}