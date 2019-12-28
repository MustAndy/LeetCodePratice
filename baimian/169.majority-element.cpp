/*
 * @lc app=leetcode id=169 lang=cpp
 *
 * [169] Majority Element
 *
 * https://leetcode.com/problems/majority-element/description/
 *
 * algorithms
 * Easy (53.74%)
 * Likes:    1922
 * Dislikes: 164
 * Total Accepted:    426.6K
 * Total Submissions: 791.3K
 * Testcase Example:  '[3,2,3]'
 *
 * Given an array of size n, find the majority element. The majority element is
 * the element that appears more than ⌊ n/2 ⌋ times.
 * 
 * You may assume that the array is non-empty and the majority element always
 * exist in the array.
 * 
 * Example 1:
 * 
 * 
 * Input: [3,2,3]
 * Output: 3
 * 
 * Example 2:
 * 
 * 
 * Input: [2,2,1,1,1,2,2]
 * Output: 2
 * 
 * 
 */
#include <vector>
#include <unordered_map>
using namespace std;
class Solution
{
public:
    int majorityElement1(vector<int> &nums)
    {
        unordered_map<int, int> counter;
        for (int num : nums)
        {
            if (++counter[num] > nums.size() / 2)
            {
                return num;
            }
        }
        return 0;
    }

    int majorityElement(vector<int> &nums)
    {
        nth_element(nums.begin(), nums.begin() + nums.size() / 2, nums.end());
        return nums[nums.size() / 2];
    }
};
