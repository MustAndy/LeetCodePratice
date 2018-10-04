/*
 * @Author: AndyWong
 * @Date: 2018-09-19 16:56:40
 * @Last Modified by:   AndyWong
 * @Last Modified time: 2018-09-19 16:56:40
 */
/*
 * [7] Reverse Integer
 *
 * https://leetcode.com/problems/reverse-integer/description/
 *
 * algorithms
 * Easy (24.42%)
 * Total Accepted:    469.8K
 * Total Submissions: 1.9M
 * Testcase Example:  '123'
 *
 * Given a 32-bit signed integer, reverse digits of an integer.
 *
 * Example 1:
 *
 *
 * Input: 123
 * Output: 321
 *
 *
 * Example 2:
 *
 *
 * Input: -123
 * Output: -321
 *
 *
 * Example 3:
 *
 *
 * Input: 120
 * Output: 21
 *
 *
 * Note:
 * Assume we are dealing with an environment which could only store integers
 * within the 32-bit signed integer range: [−231,  231 − 1]. For the purpose of
 * this problem, assume that your function returns 0 when the reversed integer
 * overflows.
 *
 */

#include <limits.h>

class Solution {
public:
  int reverse(int x) {
    bool isNegi = false;
    if (x < 0) {
      x *= -1;
      isNegi = true;
    }
    int result = 0;
    while (x != 0) {
      int pop = x % 10;
      x /= 10;
      if (result > INT_MAX / 10 || (result == INT_MAX / 10 && pop > 7))
        return 0;
      if (result < INT_MIN / 10 || (result == INT_MIN / 10 && pop < -8))
        return 0;
      result = result * 10 + pop;
    }
    if (isNegi)
      result *= -1;
    return result;
  }
};
