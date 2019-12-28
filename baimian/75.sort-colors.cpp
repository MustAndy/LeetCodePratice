/*
 * @lc app=leetcode id=75 lang=cpp
 *
 * [75] Sort Colors
 *
 * https://leetcode.com/problems/sort-colors/description/
 *
 * algorithms
 * Medium (42.94%)
 * Likes:    1861
 * Dislikes: 167
 * Total Accepted:    345.3K
 * Total Submissions: 803.7K
 * Testcase Example:  '[2,0,2,1,1,0]'
 *
 * Given an array with n objects colored red, white or blue, sort them in-place
 * so that objects of the same color are adjacent, with the colors in the order
 * red, white and blue.
 * 
 * Here, we will use the integers 0, 1, and 2 to represent the color red,
 * white, and blue respectively.
 * 
 * Note: You are not suppose to use the library's sort function for this
 * problem.
 * 
 * Example:
 * 
 * 
 * Input: [2,0,2,1,1,0]
 * Output: [0,0,1,1,2,2]
 * 
 * Follow up:
 * 
 * 
 * A rather straight forward solution is a two-pass algorithm using counting
 * sort.
 * First, iterate the array counting number of 0's, 1's, and 2's, then
 * overwrite array with total number of 0's, then 1's and followed by 2's.
 * Could you come up with a one-pass algorithm using only constant space?
 * 
 * 
 */
#define RED 0
#define WHITE 1
#define BLUE 2
class Solution
{
public:
    void sortColors(vector<int> &nums)
    {
        int i = 0, j = i, k = nums.size() - 1;

        while (j <= k)
        {
            if (nums[j] == 0)
                swap(nums[i++], nums[j++]);
            else if (nums[j] == 1)
                j++;
            else
                swap(nums[k--], nums[j]);
        }
    }
    void sortColors1(vector<int> &nums)
    {
        vector<int> result;
        int length = nums.size();
        int red = 0, white = 0, blue = 0;
        for (int i = 0; i < length; ++i)
            if (nums[i] == RED)
                ++red;
            else if (nums[i] == WHITE)
                ++white;
            else if (nums[i] == BLUE)
                ++blue;

        for (int i = 0; i < red; ++i)
            result.push_back(0);

        for (int i = 0; i < white; ++i)
            result.push_back(1);

        for (int i = 0; i < blue; ++i)
            result.push_back(2);

        nums = result;
    }
};
