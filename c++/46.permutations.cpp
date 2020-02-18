/*
 * [46] Permutations
 *
 * https://leetcode.com/problems/permutations/description/
 *
 * algorithms
 * Medium (50.45%)
 * Total Accepted:    286K
 * Total Submissions: 566.9K
 * Testcase Example:  '[1,2,3]'
 *
 * Given a collection of distinct integers, return all possible permutations.
 *
 * Example:
 *
 *
 * Input: [1,2,3]
 * Output:
 * [
 * ⁠ [1,2,3],
 * ⁠ [1,3,2],
 * ⁠ [2,1,3],
 * ⁠ [2,3,1],
 * ⁠ [3,1,2],
 * ⁠ [3,2,1]
 * ]
 *
 *
 */

#include <vector>
using namespace std;
class Solution
{
  public:
    vector<vector<int>> permute(vector<int> &nums)
    {
        vector<vector<int>> result;
        vector<int> tempResult;
        vector<int> isVaild(nums.size(), 0);
        permuteDFS(nums, 0, isVaild, tempResult, result);
        return result;
    }

    void permuteDFS(vector<int> &nums, int level, vector<int> &isVaild,
                    vector<int> &tempResult, vector<vector<int>> &result)
    {
        if (level == nums.size())
            result.push_back(tempResult);
        else
        {
            for (int i = 0; i < nums.size(); ++i)
            {
                if (isVaild[i] == 0)
                {
                    isVaild[i] = 1;
                    tempResult.push_back(nums[i]);
                    permuteDFS(nums, level + 1, isVaild, tempResult, result);
                    tempResult.pop_back();
                    isVaild[i] = 0;
                }
            }
        }
    }
};
