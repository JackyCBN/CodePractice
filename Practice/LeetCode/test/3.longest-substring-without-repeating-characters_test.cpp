#include "headers.h"
#include "3.longest-substring-without-repeating-characters.cpp"

TEST(lengthOfLongestSubstring, lengthOfLongestSubstring_1)
{
    Solution s;
    //vector<int> in = {1, 2, 3};
    //int ans = 1;
    EXPECT_EQ(s.lengthOfLongestSubstring("abcabcbb"), 3);
}

TEST(lengthOfLongestSubstring, lengthOfLongestSubstring_2)
{
    Solution s;
    //vector<int> in = {1, 2, 3};
    //int ans = 1;
    EXPECT_EQ(s.lengthOfLongestSubstring("bbbbb"), 1);
}

TEST(lengthOfLongestSubstring, lengthOfLongestSubstring_3)
{
    Solution s;
    //vector<int> in = {1, 2, 3};
    //int ans = 1;
    EXPECT_EQ(s.lengthOfLongestSubstring("pwwkew"), 3);
}
int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}