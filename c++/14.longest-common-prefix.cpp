/*
 * [14] Longest Common Prefix
 *
 * https://leetcode.com/problems/longest-common-prefix/description/
 *
 * algorithms
 * Easy (31.91%)
 * Total Accepted:    319K
 * Total Submissions: 999.5K
 * Testcase Example:  '["flower","flow","flight"]'
 *
 * Write a function to find the longest common prefix string amongst an array
 * of strings.
 *
 * If there is no common prefix, return an empty string "".
 *
 * Example 1:
 *
 *
 * Input: ["flower","flow","flight"]
 * Output: "fl"
 *
 *
 * Example 2:
 *
 *
 * Input: ["dog","racecar","car"]
 * Output: ""
 * Explanation: There is no common prefix among the input strings.
 *
 *
 * Note:
 *
 * All given inputs are in lowercase letters a-z.
 *
 */

#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Solution
{
  public:
    string longestCommonPrefix(vector<string> &strs)
    {
        string a;
        int marks = 0;
        if (strs.size() == 0)
            return a;
        if (strs.size() == 1)
            return strs[0];
        int length = strs[0].length();
        int i = 0;
        int j = 0;
        for (j = 0; j < (strs.size() - 1); j++)
        {
            if (strs[j].length() > strs[j + 1].length())
                length = strs[j + 1].length();
        }
        cout << length;
        for (i = 0; i < length; i++)
        {
            for (j = 0; j < (strs.size() - 1); j++)
            {
                if (strs[j][i] == strs[j + 1][i])
                    continue;
                else
                {

                    a = strs[j].substr(0, i);
                    return a;
                }
            }
        }
        a = strs[j].substr(0, i);
        return a;
    }
};
