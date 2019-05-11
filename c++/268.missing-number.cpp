/*
 * @lc app=leetcode id=268 lang=cpp
 *
 * [268] Missing Number
 *
 * https://leetcode.com/problems/missing-number/description/
 *
 * algorithms
 * Easy (46.99%)
 * Total Accepted:    232.1K
 * Total Submissions: 494K
 * Testcase Example:  '[3,0,1]'
 *
 * Given an array containing n distinct numbers taken from 0, 1, 2, ..., n,
 * find the one that is missing from the array.
 * 
 * Example 1:
 * 
 * 
 * Input: [3,0,1]
 * Output: 2
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [9,6,4,2,3,5,7,0,1]
 * Output: 8
 * 
 * 
 * Note:
 * Your algorithm should run in linear runtime complexity. Could you implement
 * it using only constant extra space complexity?
 */
#include <iostream>
#include <vector>
using namespace std;
class Solution
{
  public:
    int missingNumber(vector<int> &nums)
    {
        // if (nums.size() <= 0)
        //     return 0;
        int a[nums.size() + 1] = {0};
        for (int i = 0; i < nums.size(); i++)
        {
            a[nums[i]] = 1;
        }
        for (int i = 0; i < nums.size() + 1; i++)
        {
            //cout << a[i] << endl;
            if (a[i] == 0)
                return i;
        }
    }
};
