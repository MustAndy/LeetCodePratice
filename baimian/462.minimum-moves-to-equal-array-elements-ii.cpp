/*
 * @lc app=leetcode id=462 lang=cpp
 *
 * [462] Minimum Moves to Equal Array Elements II
 *
 * https://leetcode.com/problems/minimum-moves-to-equal-array-elements-ii/description/
 *
 * algorithms
 * Medium (52.67%)
 * Likes:    377
 * Dislikes: 31
 * Total Accepted:    37.5K
 * Total Submissions: 71.2K
 * Testcase Example:  '[1,2,3]'
 *
 * Given a non-empty integer array, find the minimum number of moves required
 * to make all array elements equal, where a move is incrementing a selected
 * element by 1 or decrementing a selected element by 1.
 * 
 * You may assume the array's length is at most 10,000.
 * 
 * Example:
 * 
 * Input:
 * [1,2,3]
 * 
 * Output:
 * 2
 * 
 * Explanation:
 * Only two moves are needed (remember each move increments or decrements one
 * element):
 * 
 * [1,2,3]  =>  [2,2,3]  =>  [2,2,2]
 * 
 * 
 */
#include <vector>
using namespace std;
class Solution
{
public:
    int minMoves2(vector<int> &nums)
    {
        int res = 0, n = nums.size(), mid = n / 2;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n; ++i)
        {
            res += abs(nums[i] - nums[mid]);
        }
        return res;
    }
};
