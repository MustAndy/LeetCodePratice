/*
 * [387] First Unique Character in a String
 *
 * https://leetcode.com/problems/first-unique-character-in-a-string/description/
 *
 * algorithms
 * Easy (47.61%)
 * Total Accepted:    169.7K
 * Total Submissions: 356.4K
 * Testcase Example:  '"leetcode"'
 *
 *
 * Given a string, find the first non-repeating character in it and return it's
 * index. If it doesn't exist, return -1.
 *
 * Examples:
 *
 * s = "leetcode"
 * return 0.
 *
 * s = "loveleetcode",
 * return 2.
 *
 *
 *
 *
 * Note: You may assume the string contain only lowercase letters.
 *
 */
#include <unordered_map>
using namespace std;
class Solution
{
  public:
    int firstUniqChar(string s)
    {
        int m[256] = {0};
        for (auto c : s)
            ++m[c];
        for (int i = 0; i < s.size(); ++i)
        {
            if (m[s[i]] == 1)
                return i;
        }
        return -1;
    }
};
