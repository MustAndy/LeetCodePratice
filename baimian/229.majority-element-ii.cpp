/*
 * @lc app=leetcode id=229 lang=cpp
 *
 * [229] Majority Element II
 *
 * https://leetcode.com/problems/majority-element-ii/description/
 *
 * algorithms
 * Medium (32.83%)
 * Likes:    990
 * Dislikes: 117
 * Total Accepted:    110.4K
 * Total Submissions: 335.2K
 * Testcase Example:  '[3,2,3]'
 *
 * Given an integer array of size n, find all elements that appear more than ⌊
 * n/3 ⌋ times.
 * 
 * Note: The algorithm should run in linear time and in O(1) space.
 * 
 * Example 1:
 * 
 * 
 * Input: [3,2,3]
 * Output: [3]
 * 
 * Example 2:
 * 
 * 
 * Input: [1,1,1,3,3,2,2,2]
 * Output: [1,2]
 * 
 */
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;
class Solution
{
public:
    vector<int> majorityElement(vector<int> &nums)
    {
        vector<int> result;

        int length = nums.size();
        sort(nums.begin(), nums.end());
        for (int i = 0; i < length;)
        {
            int base = nums[i];
            int counter = 0;
            while (i < length && nums[i] == base)
            {
                i++;
                counter++;
            }
            if (counter > length / 3)
                result.push_back(base);
        }
        return result;
    }
    vector<int> majorityElement_1(vector<int> &nums)
    {
        vector<int> result;
        unordered_map<int, int> record;
        int length = nums.size();
        for (int a : nums)
        {
            ++record[a];
        }

        for (unordered_map<int, int>::iterator iter = record.begin(); iter != record.end(); iter++)
        {
            if (iter->second > length / 3)
                result.push_back(iter->first);
        }
        return result;
    }
};
