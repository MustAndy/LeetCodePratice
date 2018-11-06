/*
 * [40] Combination Sum II
 *
 * https://leetcode.com/problems/combination-sum-ii/description/
 *
 * algorithms
 * Medium (37.82%)
 * Total Accepted:    172.9K
 * Total Submissions: 457.1K
 * Testcase Example:  '[10,1,2,7,6,1,5]\n8'
 *
 * Given a collection of candidate numbers (candidates) and a target number
 * (target), find all unique combinations in candidates where the candidate
 * numbers sums to target.
 *
 * Each number in candidates may only be used once in the combination.
 *
 * Note:
 *
 *
 * All numbers (including target) will be positive integers.
 * The solution set must not contain duplicate combinations.
 *
 *
 * Example 1:
 *
 *
 * Input: candidates = [10,1,2,7,6,1,5], target = 8,
 * A solution set is:
 * [
 * ⁠ [1, 7],
 * ⁠ [1, 2, 5],
 * ⁠ [2, 6],
 * ⁠ [1, 1, 6]
 * ]
 *
 *
 * Example 2:
 *
 *
 * Input: candidates = [2,5,2,1,2], target = 5,
 * A solution set is:
 * [
 * [1,2,2],
 * [5]
 * ]
 *
 *
 */

#include <algorithm>
#include <vector>
using namespace std;
class Solution
{
  public:
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
    {
        vector<vector<int>> result;
        vector<int> tempres;
        sort(candidates.begin(), candidates.end());
        combinationSum2DFS(candidates, target, 0, tempres, result);
        return result;
    }
    void combinationSum2DFS(vector<int> num, int target, int level,
                            vector<int> &tempres, vector<vector<int>> &result)
    {
        if (target < 0)
            return;
        else if (target == 0)
        {
            result.push_back(tempres);
        }
        else
        {
            for (int i = level; i < num.size(); ++i)
            {
                if (i > level && num[i] == num[i - 1])
                    continue;
                tempres.push_back(num[i]);
                combinationSum2DFS(num, target - num[i], i + 1, tempres, result);
                tempres.pop_back();
            }
        }
    }
};
