/*
 * @lc app=leetcode id=4 lang=cpp
 *
 * [4] Median of Two Sorted Arrays
 */
#include <utility>
//#include <iostream>
using namespace std;

// @lc code=start
// 2085/2085 cases passed (16 ms)
// Your runtime beats 90.87 % of cpp submissions
// Your memory usage beats 100 % of cpp submissions (8.5 MB)

class Solution {
private:
    inline void getMiddleIndex(vector<int>& nums, pair<int,int>& r, int& lo, int& hi)
    {
        int len = r.second - r.first;
        int half = r.first  + len/ 2;
        bool odd = (len & 1) != 0;
        if(odd)
        {
            lo = hi = half;
        }
        else
        {
            hi = half;
            lo = half - 1;
        }
    }

    inline double findMidian(vector<int>& nums, pair<int,int>& r)
    {
         int lo, hi;
        getMiddleIndex(nums, r,lo, hi);
        bool isOdd = lo == hi;
        int loVal = nums[lo];
        int hiVal = nums[hi];

        return isOdd ? loVal : (double)(loVal+hiVal) / 2;
    }

    inline double findMidian_1(vector<int>& nums, pair<int,int>& r,int insertVal)
    {
        int lo, hi;
        getMiddleIndex(nums, r,lo, hi);
        bool isOdd = lo == hi;
        int loVal = nums[lo];
        int hiVal = nums[hi];

        if(isOdd)
        {
            if(insertVal<loVal)
            {
                int val  = (lo <= r.first) ? insertVal : max(insertVal, nums[lo-1]);
                return (double)(val + loVal) / 2;
            }
            else
            {

                int val  = (hi >= r.second-1) ? insertVal : min(insertVal, nums[hi+1]);
                //cout<<"findMidian_1:"<<hi << "  r.second:"<< r.second<<"  val:"<<val<<endl;
                return (double)(val + hiVal) / 2;
            }
        }

        // even
        return (insertVal < loVal) 
                    ? loVal 
                    : min(insertVal, hiVal); 
    }

public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // range is [)
        using range = pair<int,int>;
        range v1Range{0, nums1.size()};
        range v2Range{0, nums2.size()};

        int     len_1 = v1Range.second - v1Range.first;
        int     len_2 = v2Range.second - v2Range.first;
        while (len_1 > 1 && len_2>1)
        {
            //cout<<"111111111len_1:"<<len_1 << "  len_2:"<<len_2<<endl;
            int     half_1 = len_1 / 2;
            int     half_2 = len_2 / 2;
            bool    odd_1  = (len_1 & 1) != 0;
            bool    odd_2  = (len_2 & 1) != 0;
            int     offset_1 = odd_1 ? 0 :-1;
            int     offset_2 = odd_2 ? 0 :-1;

            int loMiddle_1 = v1Range.first + half_1 + offset_1;
            int hiMiddle_1 = loMiddle_1 + (-offset_1);
            int loMiddle_2 = v2Range.first + half_2 + offset_2;
            int hiMiddle_2 = loMiddle_2 + (-offset_2);
            int max_loMiddle_val = max(nums1[loMiddle_1], nums2[loMiddle_2]);
            int min_hiMiddle_val = min(nums1[hiMiddle_1], nums2[hiMiddle_2]);

            if(max_loMiddle_val<=min_hiMiddle_val)
            {
                return (double)(min_hiMiddle_val + max_loMiddle_val) / 2;
            }
            else
            {
                int half = min(half_1, half_2);
                if(nums1[hiMiddle_1] < nums2[loMiddle_2])
                {
                    v1Range.first += half;
                    v2Range.second-=half;
                }
                else if(nums1[loMiddle_1] > nums2[hiMiddle_2])
                {
                     
                    v2Range.first += half;
                    v1Range.second -= half;
                }
                else
                {
                    //assert(false && "why!!!");
                }
                len_1 = v1Range.second - v1Range.first;
                len_2 = v2Range.second - v2Range.first;
            }    
        }
       // cout<<"222222222len_1:"<<v1Range.first<<"  "<< len_1 << " len_2: "<<v2Range.first<<"  "<<len_2<<endl;
        //assert(len_1<=1 || len_2<=1);
        if(len_1 == 0 || len_2 == 0)
        {
            return len_1 == 0 ? findMidian(nums2, v2Range) : findMidian(nums1, v1Range);
        }

        return len_1 == 1 
                ? findMidian_1(nums2, v2Range, nums1[v1Range.first])
                : findMidian_1(nums1, v1Range, nums2[v2Range.first]);
    }
};

/*
class Solution {
public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		int n = nums1.size();
		int m = nums2.size();

		if (n > m)  //保证数组1一定最短
		{
			return findMedianSortedArrays(nums2, nums1);
		}

		// Ci 为第i个数组的割,比如C1为2时表示第1个数组只有2个元素。LMaxi为第i个数组割后的左元素。RMini为第i个数组割后的右元素。
		int LMax1, LMax2, RMin1, RMin2, c1, c2, lo = 0, hi = 2 * n;  //我们目前是虚拟加了'#'所以数组1是2*n长度

		while (lo <= hi)   //二分
		{
			c1 = (lo + hi) / 2;  //c1是二分的结果
			c2 = m + n - c1;

			LMax1 = (c1 == 0) ? INT_MIN : nums1[(c1 - 1) / 2];
			RMin1 = (c1 == 2 * n) ? INT_MAX : nums1[c1 / 2];
			LMax2 = (c2 == 0) ? INT_MIN : nums2[(c2 - 1) / 2];
			RMin2 = (c2 == 2 * m) ? INT_MAX : nums2[c2 / 2];

			if (LMax1 > RMin2)
				hi = c1 - 1;
			else if (LMax2 > RMin1)
				lo = c1 + 1;
			else
				break;
		}
		return (max(LMax1, LMax2) + min(RMin1, RMin2)) / 2.0;
	}
};
*/
// @lc code=end

