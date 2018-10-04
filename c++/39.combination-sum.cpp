/*
 * [39] Combination Sum
 *
 * https://leetcode.com/problems/combination-sum/description/
 *
 * algorithms
 * Medium (43.64%)
 * Total Accepted:    253.5K
 * Total Submissions: 580.9K
 * Testcase Example:  '[2,3,6,7]\n7'
 *
 * Given a set of candidate numbers (candidates) (without duplicates) and a
 * target number (target), find all unique combinations in candidates where the
 * candidate numbers sums to target.
 *
 * The same repeated number may be chosen from candidates unlimited number of
 * times.
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
 * Input: candidates = [2,3,6,7], target = 7,
 * A solution set is:
 * [
 * ⁠ [7],
 * ⁠ [2,2,3]
 * ]
 *
 *
 * Example 2:
 *
 *
 * Input: candidates = [2,3,5], target = 8,
 * A solution set is:
 * [
 * [2,2,2,2],
 * [2,3,3],
 * [3,5]
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
    void combinationSumDFS(vector<int> candidates, int target, int level,
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
            for (int i = level; i < candidates.size(); ++i)
            {
                tempres.push_back(candidates[i]);
                combinationSumDFS(candidates, target - candidates[i], i, tempres,
                                  result);
                tempres.pop_back();
            }
        }
    }

    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        vector<vector<int>> result;
        vector<int> tempres;
        combinationSumDFS(candidates, target, 0, tempres, result);
        sort(candidates.begin(), candidates.end());
        return result;
    }
};
