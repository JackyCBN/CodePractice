/*
 * @lc app=leetcode id=3 lang=cpp
 *
 * [3] Longest Substring Without Repeating Characters
 */

/*
987/987 cases passed (8 ms)
Your runtime beats 94.7 % of cpp submissions
Your memory usage beats 100 % of cpp submissions (8.2 MB)
*/
// @lc code=start
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // 0 present not record. 1-index
        int indexs[128] = {0};

        int start = 1;
        int maxlen = 0;
        int len = s.size();
        for(int i=1; i<=len;++i)
        {
            int j = s[i-1];

            if(indexs[j] > 0 && start <= indexs[j])
            {
                maxlen  = std::max(i-start, maxlen);
                start = indexs[j]+1;
            }
            indexs[j] = i;
        }

         maxlen  = std::max(len-start+1, maxlen);
        return maxlen;
    }
};
// @lc code=end

