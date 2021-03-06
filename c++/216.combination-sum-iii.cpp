/*
 * [216] Combination Sum III
 *
 * https://leetcode.com/problems/combination-sum-iii/description/
 *
 * algorithms
 * Medium (48.75%)
 * Total Accepted:    100.2K
 * Total Submissions: 205.5K
 * Testcase Example:  '3\n7'
 *
 *
 * Find all possible combinations of k numbers that add up to a number n, given
 * that only numbers from 1 to 9 can be used and each combination should be a
 * unique set of numbers.
 *
 * Note:
 *
 *
 * All numbers will be positive integers.
 * The solution set must not contain duplicate combinations.
 *
 *
 * Example 1:
 *
 *
 * Input: k = 3, n = 7
 * Output: [[1,2,4]]
 *
 *
 * Example 2:
 *
 *
 * Input: k = 3, n = 9
 * Output: [[1,2,6], [1,3,5], [2,3,4]]
 *
 *
 *
 */
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
  vector<vector<int>> combinationSum3(int k, int n) {
    vector<vector<int>> result;
    vector<int> tempResult;
    combinationSum3DFS(k, n, 1, tempResult, result);
    return result;
  }

  void combinationSum3DFS(int k, int n, int level, vector<int> &tempResult,
                          vector<vector<int>> &result) {
    if (n < 0)
      return;
    if (n == 0 && tempResult.size() == k)
      result.push_back(tempResult);
    for (int i = level; i <= 9; ++i) {
      tempResult.push_back(i);
      combinationSum3DFS(k, n - i, i + 1, tempResult, result);
      tempResult.pop_back();
    }
  }
};
