/*
 * @lc app=leetcode id=290 lang=cpp
 *
 * [290] Word Pattern
 *
 * https://leetcode.com/problems/word-pattern/description/
 *
 * algorithms
 * Easy (35.45%)
 * Likes:    874
 * Dislikes: 123
 * Total Accepted:    168.1K
 * Total Submissions: 465.2K
 * Testcase Example:  '"abba"\n"dog cat cat dog"'
 *
 * Given a pattern and a string str, find if str follows the same pattern.
 * 
 * Here follow means a full match, such that there is a bijection between a
 * letter in pattern and a non-empty word in str.
 * 
 * Example 1:
 * 
 * 
 * Input: pattern = "abba", str = "dog cat cat dog"
 * Output: true
 * 
 * Example 2:
 * 
 * 
 * Input:pattern = "abba", str = "dog cat cat fish"
 * Output: false
 * 
 * Example 3:
 * 
 * 
 * Input: pattern = "aaaa", str = "dog cat cat dog"
 * Output: false
 * 
 * Example 4:
 * 
 * 
 * Input: pattern = "abba", str = "dog dog dog dog"
 * Output: false
 * 
 * Notes:
 * You may assume pattern contains only lowercase letters, and str contains
 * lowercase letters that may be separated by a single space.
 * 
 */

// @lc code=start
#include <string>
#include <map>
#include <sstream>
using namespace std;
class Solution
{
public:
    bool wordPattern(string pattern, string str)
    {
        map<char, int> m1;
        map<string, int> m2;
        istringstream in(str);
        int i = 0, n = pattern.size();
        for (string word; in >> word; ++i)
        {
            if (i == n || m1[pattern[i]] != m2[word])
                return false;
            m1[pattern[i]] = m2[word] = i + 1;
        }
        return i == n;
    }
};
// @lc code=end
