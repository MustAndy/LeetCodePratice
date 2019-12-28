/*
 * @lc app=leetcode id=260 lang=cpp
 *
 * [260] Single Number III
 *
 * https://leetcode.com/problems/single-number-iii/description/
 *
 * algorithms
 * Medium (57.86%)
 * Likes:    971
 * Dislikes: 80
 * Total Accepted:    114.3K
 * Total Submissions: 196.9K
 * Testcase Example:  '[1,2,1,3,2,5]'
 *
 * Given an array of numbers nums, in which exactly two elements appear only
 * once and all the other elements appear exactly twice. Find the two elements
 * that appear only once.
 * 
 * Example:
 * 
 * 
 * Input:  [1,2,1,3,2,5]
 * Output: [3,5]
 * 
 * Note:
 * 
 * 
 * The order of the result is not important. So in the above example, [5, 3] is
 * also correct.
 * Your algorithm should run in linear runtime complexity. Could you implement
 * it using only constant space complexity?
 * 
 */



#include <vector>
using namespace std;
class Solution
{
public:
    vector<int> singleNumber(vector<int> &nums)
    {
        int length = nums.size();
        int result = 0;
        vector<int> res(2, 0);
        for (int i = 0; i < length; ++i)
        {
            result ^= nums[i];
        }
        int last = result & (~(result - 1));
        cout << result << endl
             << last;
        for (int i = 0; i < length; ++i)
        {
            if ((last & nums[i]) != 0)
                res[0] ^= nums[i];
            else
                res[1] ^= nums[i];
        }

        return res;
    }
};
