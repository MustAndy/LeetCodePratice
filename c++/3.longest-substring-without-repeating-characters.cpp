/*
 * @Author: AndyWong 
 * @Date: 2018-09-19 16:56:48 
 * @Last Modified by:   AndyWong 
 * @Last Modified time: 2018-09-19 16:56:48 
 */
/*
 * [3] Longest Substring Without Repeating Characters
 *
 * https://leetcode.com/problems/longest-substring-without-repeating-characters/description/
 *
 * algorithms
 * Medium (25.02%)
 * Total Accepted:    578.4K
 * Total Submissions: 2.3M
 * Testcase Example:  '"abcabcbb"'
 *
 * Given a string, find the length of the longest substring without repeating
 * characters.
 *
 *
 * Example 1:
 *
 *
 * Input: "abcabcbb"
 * Output: 3
 * Explanation: The answer is "abc", with the length of 3.
 *
 *
 *
 * Example 2:
 *
 *
 * Input: "bbbbb"
 * Output: 1
 * Explanation: The answer is "b", with the length of 1.
 *
 *
 *
 * Example 3:
 *
 *
 * Input: "pwwkew"
 * Output: 3
 * Explanation: The answer is "wke", with the length of 3.
 * ⁠            Note that the answer must be a substring, "pwke" is a
 * subsequence and not a substring.
 *
 *
 *
 *
 *
 */

#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Solution
{
  public:
    int findSame(string temp)
    {
        int length = temp.length();
        for (int i = 0; i < length; i++)
            for (int j = i + 1; j < length; j++)
                if (temp[i] == temp[j])
                {
                    return j;
                }
        return -1;
    }
    int lengthOfLongestSubstring1(string s)
    {
        int i = 0, j = s.length(), length = s.length(), count = 0;
        for (i = 0; i < length; i++)
        {
            for (j = s.length() - i; j >= count; j--)
            {
                string temp = s.substr(i, j);
                int tempLength = temp.length();
                int isSame = findSame(temp);
                if ((isSame == -1) && (count < tempLength))
                    count = tempLength;
                else
                    j = isSame + 1;
            }
        }
        return count;
    }
    int lengthOfLongestSubstring(string s)
    {
        vector<int> mymap(255, -1);
        int len = 0, i = -1, tmp;
        int length = s.length();
        for (int j = 0; j < length; j++)
        {
            tmp = mymap[s.at(j)];
            i = std::max(tmp, i);
            mymap[s.at(j)] = j;
            len = std::max(len, (j - i));
        }
        return len;
    }
};
