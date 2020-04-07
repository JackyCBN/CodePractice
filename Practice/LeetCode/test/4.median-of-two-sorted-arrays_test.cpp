#include "headers.h"
#include "4.median-of-two-sorted-arrays.cpp"

TEST(findMedianSortedArrays, findMedianSortedArrays_1)
{
    Solution s;
    vector<int> v1 = {1, 3};
    vector<int> v2 = {2};
    cout<<"findMedianSortedArrays_111111111111111"<<endl;
    //int ans = 1;
    EXPECT_DOUBLE_EQ(s.findMedianSortedArrays(v1, v2), 2.0);
}

TEST(findMedianSortedArrays, findMedianSortedArrays_2)
{
    Solution s;
    vector<int> v1 = {1, 2};
    vector<int> v2 = {3, 4};
        cout<<"findMedianSortedArrays_222222222222"<<endl;
    //int ans = 1;
    EXPECT_DOUBLE_EQ(s.findMedianSortedArrays(v1, v2), 2.5);
}

TEST(findMedianSortedArrays, findMedianSortedArrays_3)
{
    Solution s;
    vector<int> v1 = {};
    vector<int> v2 = {1};
    //int ans = 1;
    EXPECT_DOUBLE_EQ(s.findMedianSortedArrays(v1, v2), 1.0);
}

TEST(findMedianSortedArrays, findMedianSortedArrays_4)
{
    Solution s;
    vector<int> v1 = {};
    vector<int> v2 = {2,3};
    //int ans = 1;
    EXPECT_DOUBLE_EQ(s.findMedianSortedArrays(v1, v2), 2.5);
}

TEST(findMedianSortedArrays, findMedianSortedArrays_5)
{
    Solution s;
    vector<int> v1 = {3};
    vector<int> v2 = {-2,-1};
    //int ans = 1;
    EXPECT_DOUBLE_EQ(s.findMedianSortedArrays(v1, v2), -1.0);
}
TEST(findMedianSortedArrays, findMedianSortedArrays_6)
{
    Solution s;
    vector<int> v1 = {0,0};
    vector<int> v2 = {0,0};
    //int ans = 1;
    EXPECT_DOUBLE_EQ(s.findMedianSortedArrays(v1, v2), 0);
}

TEST(findMedianSortedArrays, findMedianSortedArrays_7)
{
    Solution s;
    vector<int> v1 = {3};
    vector<int> v2 = {1,2,4};
    //int ans = 1;
    EXPECT_DOUBLE_EQ(s.findMedianSortedArrays(v1, v2), 2.5);
}
int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
    //    Solution s;
    // vector<int> v1 = {1, 2};
    // vector<int> v2 = {3, 4};
    // double b = s.findMedianSortedArrays(v1, v2);
    // std::cout<<"ret:"<<b<<endl;
    return 0;

}