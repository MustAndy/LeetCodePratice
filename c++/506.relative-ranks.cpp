/*
 * @lc app=leetcode id=506 lang=cpp
 *
 * [506] Relative Ranks
 *
 * https://leetcode.com/problems/relative-ranks/description/
 *
 * algorithms
 * Easy (47.64%)
 * Total Accepted:    38.3K
 * Total Submissions: 80.3K
 * Testcase Example:  '[5,4,3,2,1]'
 *
 * 
 * Given scores of N athletes, find their relative ranks and the people with
 * the top three highest scores, who will be awarded medals: "Gold Medal",
 * "Silver Medal" and "Bronze Medal".
 * 
 * Example 1:
 * 
 * Input: [5, 4, 3, 2, 1]
 * Output: ["Gold Medal", "Silver Medal", "Bronze Medal", "4", "5"]
 * Explanation: The first three athletes got the top three highest scores, so
 * they got "Gold Medal", "Silver Medal" and "Bronze Medal". For the left two
 * athletes, you just need to output their relative ranks according to their
 * scores.
 * 
 * 
 * 
 * Note:
 * 
 * N is a positive integer and won't exceed 10,000.
 * All the scores of athletes are guaranteed to be unique.
 * 
 * 
 * 
 */
#include <vector>
#include <string>
#include <map>
#include <algorithm>
using namespace std;
class Solution
{
  public:
    vector<string> findRelativeRanks(vector<int> &nums)
    {
        int n = nums.size(), cnt = 1;
        vector<string> res(n, "");
        map<int, int> m;
        for (int i = 0; i < n; ++i)
        {
            m[nums[i]] = i;
        }
        for (auto it = m.rbegin(); it != m.rend(); ++it)
        {
            if (cnt == 1)
                res[it->second] = "Gold Medal";
            else if (cnt == 2)
                res[it->second] = "Silver Medal";
            else if (cnt == 3)
                res[it->second] = "Bronze Medal";
            else
                res[it->second] = to_string(cnt);
            ++cnt;
        }
        return res;
    }
};
