/*
 * [47] Permutations II
 *
 * https://leetcode.com/problems/permutations-ii/description/
 *
 * algorithms
 * Medium (37.12%)
 * Total Accepted:    192.2K
 * Total Submissions: 517.8K
 * Testcase Example:  '[1,1,2]'
 *
 * Given a collection of numbers that might contain duplicates, return all
 * possible unique permutations.
 *
 * Example:
 *
 *
 * Input: [1,1,2]
 * Output:
 * [
 * ⁠ [1,1,2],
 * ⁠ [1,2,1],
 * ⁠ [2,1,1]
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
    vector<vector<int>> permuteUnique(vector<int> &nums)
    {
        vector<vector<int>> result;
        vector<int> tempResult;
        vector<int> isVaild(nums.size(), 0);
        sort(nums.begin(), nums.end());
        permuteDFS(nums, 0, isVaild, tempResult, result);
        return result;
    }

    void permuteDFS(vector<int> &nums, int level, vector<int> &isVaild,
                    vector<int> &tempResult, vector<vector<int>> &result)
    {
        if (level >= nums.size())
            result.push_back(tempResult);
        else
        {
            for (int i = 0; i < nums.size(); ++i)
            {
                if (isVaild[i] == 0)
                {
                    if (i > 0 && nums[i] == nums[i - 1] && isVaild[i - 1] == 0)
                        continue;
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
