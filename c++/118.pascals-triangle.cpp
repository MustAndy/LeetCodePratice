/*
 * [118] Pascal's Triangle
 *
 * https://leetcode.com/problems/pascals-triangle/description/
 *
 * algorithms
 * Easy (42.27%)
 * Total Accepted:    197.4K
 * Total Submissions: 467K
 * Testcase Example:  '5'
 *
 * Given a non-negative integer numRows, generate the first numRows of Pascal's
 * triangle.
 *
 *
 * In Pascal's triangle, each number is the sum of the two numbers directly
 * above it.
 *
 * Example:
 *
 *
 * Input: 5
 * Output:
 * [
    * ⁠    [1],
    * ⁠   [1,1],
    * ⁠  [1,2,1],
    * ⁠ [1,3,3,1],
    * ⁠[1,4,6,4,1]
 *   [1,5,x,x,5,1]
 * ]
 *
 *
 */
#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
  vector<vector<int>> generate(int numRows) {
    vector<vector<int>> Result;

    if (numRows <= 0) {
      return Result;
    }
    Result.assign(numRows, vector<int>(1));
    Result[0][0] = 1;
    for (int i = 1; i < numRows; i++) {
      Result[i][0] = 1;
      for (int j = 1; j < i; j++) {
        Result[i].push_back(Result[i - 1][j] + Result[i - 1][j - 1]);
      }
      Result[i].push_back(1);
    }
    return Result;
  }
};
