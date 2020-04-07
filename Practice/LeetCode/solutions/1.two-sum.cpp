/*
 * @lc app=leetcode id=1 lang=cpp
 *
 * [1] Two Sum
 */
#include <vector>
#include <unordered_map>

using namespace std;
/*
29/29 cases passed (8 ms)
Your runtime beats 93.14 % of cpp submissions
Your memory usage beats 57.77 % of cpp submissions (9.7 MB)
*/
// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> indexs;
        for (int i = 0; i < nums.size(); i++)
        {
            auto iter = indexs.find(target-nums[i]);
            if(iter!=indexs.end())
            {
                return {iter->second, i};
            }
            indexs.emplace(make_pair(nums[i],i));
        }
        return {};
    }
};
// @lc code=end

