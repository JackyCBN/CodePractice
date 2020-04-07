/*
 * @lc app=leetcode id=2 lang=cpp
 *
 * [2] Add Two Numbers
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/*
1563/1563 cases passed (20 ms)
Your runtime beats 97.49 % of cpp submissions
Your memory usage beats 5.14 % of cpp submissions (10.7 MB)
*/
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* l1Iter = l1;
        ListNode* l2Iter = l2;
        int carry = 0;
        ListNode* nodeptr = nullptr;
        
        do{
            int calc = l1Iter->val + l2Iter->val + carry;
            l1Iter->val = calc%10;
            carry = calc/10;
            //cout<<calc<<endl;
            nodeptr = l1Iter;
            l1Iter = l1Iter->next;
            l2Iter = l2Iter->next;
        }while (l1Iter!=nullptr && l2Iter!=nullptr);

        ListNode*  leftNode = l1Iter!=nullptr ? l1Iter : l2Iter;

        if(carry>0 || leftNode!=nullptr)
        {
            do
            {
                ListNode* node = nodeptr->next!=nullptr  ? nodeptr->next : new ListNode{0};
                nodeptr->next = node;
                nodeptr = node;

                int calc = (leftNode!=nullptr ? leftNode->val : 0) + carry;
                node->val = calc%10;
                carry = calc/10;

                if(leftNode)
                {
                    leftNode = leftNode->next;
                }
                
            } while (carry>0 || leftNode!=nullptr);
            
        }

        return l1;
    }
};
// @lc code=end

