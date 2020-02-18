/*
 * @lc app=leetcode id=18 lang=cpp
 *
 * [18] 4Sum
 *
 * https://leetcode.com/problems/4sum/description/
 *
 * algorithms
 * Medium (31.28%)
 * Likes:    1223
 * Dislikes: 243
 * Total Accepted:    257.3K
 * Total Submissions: 820.6K
 * Testcase Example:  '[1,0,-1,0,-2,2]\n0'
 *
 * Given an array nums of n integers and an integer target, are there elements
 * a, b, c, and d in nums such that a + b + c + d = target? Find all unique
 * quadruplets in the array which gives the sum of target.
 * 
 * Note:
 * 
 * The solution set must not contain duplicate quadruplets.
 * 
 * Example:
 * 
 * 
 * Given array nums = [1, 0, -1, 0, -2, 2], and target = 0.
 * 
 * A solution set is:
 * [
 * ⁠ [-1,  0, 0, 1],
 * ⁠ [-2, -1, 1, 2],
 * ⁠ [-2,  0, 0, 2]
 * ]
 * 
 * 
 */
#include <vector>
#include <algorithm>
using namespace std;
class Solution
{
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        vector<vector<int>> result;
        if (nums.size() < 4)
            return result;

        // vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        int length = nums.size();
        for (int i = 0; i < length - 3; ++i)
        {
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            if (nums[i] + nums[i + 1] + nums[i + 2] + nums[i + 3] > target)
                break;
            if (nums[i] + nums[length - 3] + nums[length - 2] + nums[length - 1] < target)
                continue;
            for (int j = i + 1; j < length - 2; ++j)
            {
                if (j > i + 1 && nums[j] == nums[j - 1])
                    continue;
                if (nums[i] + nums[j] + nums[j + 1] + nums[j + 2] > target)
                    break;
                if (nums[i] + nums[j] + nums[length - 2] + nums[length - 1] < target)
                    continue;

                int left = j + 1, right = length - 1;
                while (left < right)
                {
                    int sum = nums[left] + nums[right] + nums[i] + nums[j];
                    if (sum < target)
                        left++;
                    else if (sum > target)
                        right--;
                    else
                    {
                        result.push_back(vector<int>{nums[i], nums[j], nums[left], nums[right]});
                        do
                        {
                            left++;
                        } while (nums[left] == nums[left - 1] && left < right);
                        do
                        {
                            right--;
                        } while (nums[right] == nums[right + 1] && left < right);
                    }
                }
            }
        }
        return result;
    }
};
