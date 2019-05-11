/*
 * @lc app=leetcode id=283 lang=cpp
 *
 * [283] Move Zeroes
 *
 * https://leetcode.com/problems/move-zeroes/description/
 *
 * algorithms
 * Easy (53.18%)
 * Total Accepted:    396.7K
 * Total Submissions: 746K
 * Testcase Example:  '[0,1,0,3,12]'
 *
 * Given an array nums, write a function to move all 0's to the end of it while
 * maintaining the relative order of the non-zero elements.
 * 
 * Example:
 * 
 * 
 * Input: [0,1,0,3,12]
 * Output: [1,3,12,0,0]
 * 
 * Note:
 * 
 * 
 * You must do this in-place without making a copy of the array.
 * Minimize the total number of operations.
 * 
 */
#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
  void moveZeroes(vector<int> &nums)
  {
    int counter = 0;
    int temp;
    int Vsize = nums.size();
    for (int i = 0; i < Vsize; i++)
    {
      if (nums[i] == 0)
      {
      }
      else if (nums[i] != 0)
      {
        temp = nums[i];
        nums[i] = nums[counter];
        nums[counter] = temp;
        counter++;
      }
    }
  }
};
