#include "headers.h"
#include "1.two-sum.cpp"

TEST(twoSum, twoSum_1_Ascending)
{
    Solution s;
    vector<int> in = {2, 7, 11, 15};
    vector<int> ans = {0,1};
    EXPECT_EQ(s.twoSum(in,9), ans);
}

TEST(twoSum, twoSum_2_Descending)
{
    Solution s;
    vector<int> in = {15,11,7,2};
    vector<int> ans = {2,3};
    EXPECT_EQ(s.twoSum(in,9), ans);
}
TEST(twoSum, twoSum_3_Random)
{
    Solution s;
    vector<int> in = {2, 11, 7,  15};
    vector<int> ans;
    EXPECT_EQ(s.twoSum(in,19), ans);
}
TEST(twoSum, twoSum_4_Notfound)
{
    Solution s;
    vector<int> in = {2, 7, 11, 15};
    vector<int> ans;
    EXPECT_EQ(s.twoSum(in,19), ans);
}
TEST(twoSum, twoSum_5_Duplicate)
{
    Solution s;
    vector<int> in = {2, 7, 7, 15};
    vector<int> ans{1,3};
    EXPECT_EQ(s.twoSum(in,22), ans);
}
int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}