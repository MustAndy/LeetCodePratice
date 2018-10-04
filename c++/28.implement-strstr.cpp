/*
 * @Author: AndyWong
 * @Date: 2018-09-19 16:56:01
 * @Last Modified by: AndyWong
 * @Last Modified time: 2018-09-19 16:57:03
 */
/*
 * [28] Implement strStr()
 *
 * https://leetcode.com/problems/implement-strstr/description/
 *
 * algorithms
 * Easy (29.90%)
 * Total Accepted:    313.7K
 * Total Submissions: 1M
 * Testcase Example:  '"hello"\n"ll"'
 *
 * Implement strStr().
 *
 * Return the index of the first occurrence of needle in haystack, or -1 if
 * needle is not part of haystack.
 *
 * Example 1:
 *
 *
 * Input: haystack = "hello", needle = "ll"
 * Output: 2
 *
 *
 * Example 2:
 *
 *
 * Input: haystack = "aaaaa", needle = "bba"
 * Output: -1
 *
 *
 * Clarification:
 *
 * What should we return when needle is an empty string? This is a great
 * question to ask during an interview.
 *
 * For the purpose of this problem, we will return 0 when needle is an empty
 * string. This is consistent to C's strstr() and Java's indexOf().
 *
 */

#include <iostream>
#include <string>

using namespace std;
class Solution {
public:
  int strStr(string haystack, string needle) {

    if ((haystack.length() == 0 && needle.length() == 0) ||
        needle.length() == 0) {
      return 0;
    }

    bool isSame = true;
    int length = haystack.length();
    int tarlength = needle.length();
    for (int i = 0; i < length; i++) {
      if (haystack[i] == needle[0]) {
        isSame = true;
        for (int j = 0; j < tarlength; j++) {
          if (haystack[i + j] != needle[j]) {
            isSame = false;
            break;
          }
        }
        if (isSame == true)
          return i;
      }
    }
    return -1;
  }
};
