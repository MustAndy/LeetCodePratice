/*
 * @lc app=leetcode id=167 lang=cpp
 *
 * [167] Two Sum II - Input array is sorted
 *
 * https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/description/
 *
 * algorithms
 * Easy (51.08%)
 * Likes:    1022
 * Dislikes: 424
 * Total Accepted:    277.4K
 * Total Submissions: 542.8K
 * Testcase Example:  '[2,7,11,15]\n9'
 *
 * Given an array of integers that is already sorted in ascending order, find
 * two numbers such that they add up to a specific target number.
 * 
 * The function twoSum should return indices of the two numbers such that they
 * add up to the target, where index1 must be less than index2.
 * 
 * Note:
 * 
 * 
 * Your returned answers (both index1 and index2) are not zero-based.
 * You may assume that each input would have exactly one solution and you may
 * not use the same element twice.
 * 
 * 
 * Example:
 * 
 * 
 * Input: numbers = [2,7,11,15], target = 9
 * Output: [1,2]
 * Explanation: The sum of 2 and 7 is 9. Therefore index1 = 1, index2 = 2.
 * 
 */
class Solution
{
public:
    vector<int> twoSum(vector<int> &numbers, int target)
    {
        int length = numbers.size();
        vector<int> result;
        if (length == 0)
            return result;
        int i = 0, j = length - 1;

        while (i < j)
        {
            if (numbers[i] + numbers[j] == target)
            {
                result.push_back(i + 1);
                result.push_back(j + 1);
                return result;
            }
            else if (numbers[i] + numbers[j] > target)
            {
                j--;
            }
            else if (numbers[i] + numbers[j] < target)
            {
                i++;
            }
        }
        return result;
    }
};
