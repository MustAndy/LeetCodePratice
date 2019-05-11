/*
 * [38] Count and Say
 *
 * https://leetcode.com/problems/count-and-say/description/
 *
 * algorithms
 * Easy (37.81%)
 * Total Accepted:    218.3K
 * Total Submissions: 577.3K
 * Testcase Example:  '1'
 *
 * The count-and-say sequence is the sequence of integers with the first five
 * terms as following:
 *
 *
 * 1.     1
 * 2.     11
 * 3.     21
 * 4.     1211
 * 5.     111221
 *
 *
 * 1 is read off as "one 1" or 11.
 * 11 is read off as "two 1s" or 21.
 * 21 is read off as "one 2, then one 1" or 1211.
 *
 * Given an integer n, generate the nth term of the count-and-say sequence.
 *
 * Note: Each term of the sequence of integers will be represented as a
 * string.
 *
 * Example 1:
 *
 *
 * Input: 1
 * Output: "1"
 *
 *
 *
 *
 * Example 2:
 *
 *
 * Input: 4
 * Output: "1211"
 *
 *
 * Input Constraints:
 *
 * 1 <= n <= 30
 *
 */

#include <iostream>
#include <string>

using namespace std;
class Solution
{
public:
  string countAndSay(int n)
  {
    string s = "1";
    for (int i = 1; i < n; ++i)
    {
      string temp = "";
      for (int j = 0, count; j < s.size(); ++j)
      {
        for (count = 1; j < s.size() && s[j] == s[j + 1]; ++j, ++count)
          ;
        temp = temp + (char)(count + '0') + s[j];
      }
      s = temp;
    }
    return s;
  }
};
