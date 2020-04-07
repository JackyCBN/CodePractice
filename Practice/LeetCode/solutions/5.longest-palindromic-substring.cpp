/*
 * @lc app=leetcode id=5 lang=cpp
 *
 * [5] Longest Palindromic Substring
 */

// @lc code=start
class Solution {
private:
    bool isPalindrome(string& s) {
        int lo = 0;
        int hi = s.size() - 1;
 //cout<<"isPalindrome:"<<s<<endl;
        while (lo < hi)
        {
            if(s[lo++] != s[hi--])
                return false;
        }
        //cout<<"xxx:"<<s<<endl;
        return true;
    }
public:
    string longestPalindrome(string s) {
        string longStr = "";
        int longStrLen = 0;
        int len = s.size();
        for (int start = 0; start < len && start<len-longStrLen ; start++)
        {
            int sublen = len - start;
            while (sublen>0 && sublen>longStrLen)
            {
                string sub = s.substr(start, sublen);
                if(isPalindrome(sub))
                {
                    longStr = sub;
                    longStrLen = longStr.size();
                    break;
                }
                --sublen;
            }
        }
        return longStr;
    }
};
// @lc code=end

