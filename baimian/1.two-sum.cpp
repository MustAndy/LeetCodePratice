/*
 * @lc app=leetcode id=1 lang=cpp
 *
 * [1] Two Sum
 *
 * https://leetcode.com/problems/two-sum/description/
 *
 * algorithms
 * Easy (44.34%)
 * Likes:    11298
 * Dislikes: 389
 * Total Accepted:    2M
 * Total Submissions: 4.4M
 * Testcase Example:  '[2,7,11,15]\n9'
 *
 * Given an array of integers, return indices of the two numbers such that they
 * add up to a specific target.
 * 
 * You may assume that each input would have exactly one solution, and you may
 * not use the same element twice.
 * 
 * Example:
 * 
 * 
 * Given nums = [2, 7, 11, 15], target = 9,
 * 
 * Because nums[0] + nums[1] = 2 + 7 = 9,
 * return [0, 1].
 * 
 * 
 */
#include <vector>
#include <map>
using namespace std;
class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        vector<int> result;
        map<int, int> paring;
        int i = 0, j = 0, length = nums.size();
        for (int i = 0; i < length; ++i)
        {
            if (paring.find(target - nums[i]) != paring.end())
            {
                return {paring[target - nums[i]], i};
            }
            paring[nums[i]] = i;
        }

        return {};
    }
    vector<int> twoSum1(vector<int> &nums, int target)
    {
        vector<int> result;
        int i = 0, j = 0, length = nums.size();

        for (i = 0; i < length; i++)
        {
            for (j = i + 1; j < length; j++)
            {
                if (nums[j] + nums[i] == target)
                {
                    result.push_back(i);
                    result.push_back(j);
                    return result;
                }
            }
        }
        return result;
    }
};
