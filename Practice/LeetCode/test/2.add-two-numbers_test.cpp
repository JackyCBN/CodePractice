#include "headers.h"
#include "2.add-two-numbers.cpp"
using namespace LeetCode;
using namespace std;

TEST(addTwoNumbers, addTwoNumbers_1)
{
    Solution s;

    List l1({2,4,3});
    List l2({5,6,4});
    
    struct ListNode* ret = s.addTwoNumbers(l1.head, l2.head);

    EXPECT_EQ(ret->val, 7);
    ret = ret->next;
    EXPECT_EQ(ret->val, 0);
    ret = ret->next;
    EXPECT_EQ(ret->val, 8);
}

TEST(addTwoNumbers, addTwoNumbers_zero)
{
    Solution s;
    List l1({0});
    List l2({0});
    
    struct ListNode* ret = s.addTwoNumbers(l1.head, l2.head);

    EXPECT_EQ(ret->val, 0);
}

TEST(addTwoNumbers, addTwoNumbers_one_carry)
{
    Solution s;
    List l1({5});
    List l2({5});
    
    struct ListNode* ret = s.addTwoNumbers(l1.head, l2.head);

    EXPECT_EQ(ret->val, 0);
    ret = ret->next;
    EXPECT_EQ(ret->val, 1);
}

TEST(addTwoNumbers, addTwoNumbers_no_carry)
{
    Solution s;
    List l1({2,4,3});
    List l2({5,6,4});
    
    struct ListNode* ret = s.addTwoNumbers(l1.head, l2.head);

    EXPECT_EQ(ret->val, 7);
    ret = ret->next;
    EXPECT_EQ(ret->val, 0);
    ret = ret->next;
    EXPECT_EQ(ret->val, 8);
    ret = ret->next;
    EXPECT_EQ(ret, nullptr);
}

TEST(addTwoNumbers, addTwoNumbers_no_same_length)
{
    Solution s;
    List l1({0});
    List l2({7,3});
    
    struct ListNode* ret = s.addTwoNumbers(l1.head, l2.head);

    EXPECT_EQ(ret->val, 7);
    ret = ret->next;
    EXPECT_EQ(ret->val, 3);
}

TEST(addTwoNumbers, addTwoNumbers_no_same_length2)
{
    Solution s;
    List l1({9,8});
    List l2({1});
    
    struct ListNode* ret = s.addTwoNumbers(l1.head, l2.head);

    EXPECT_EQ(ret->val, 0);
    ret = ret->next;
    EXPECT_EQ(ret->val, 9);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}