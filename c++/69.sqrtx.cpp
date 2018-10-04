/*
 * @Author: AndyWong
 * @Date: 2018-09-19 16:55:51
 * @Last Modified by: AndyWong
 * @Last Modified time: 2018-09-19 16:57:05
 */
/*
 * [69] Sqrt(x)
 *
 * https://leetcode.com/problems/sqrtx/description/
 *
 * algorithms
 * Easy (29.50%)
 * Total Accepted:    269.5K
 * Total Submissions: 913.6K
 * Testcase Example:  '4'
 *
 * Implement int sqrt(int x).
 *
 * Compute and return the square root of x, where x is guaranteed to be a
 * non-negative integer.
 *
 * Since the return type is an integer, the decimal digits are truncated and
 * only the integer part of the result is returned.
 *
 * Example 1:
 *
 *
 * Input: 4
 * Output: 2
 *
 *
 * Example 2:
 *
 *
 * Input: 8
 * Output: 2
 * Explanation: The square root of 8 is 2.82842..., and since
 * the decimal part is truncated, 2 is returned.
 *
 *
 */
#include <iostream>
#include <string>

using namespace std;
class Solution {
public:
  int mySqrt1(int x) {
    long long int mult;
    if (x > 2147395600)
      return 46340;
    if (x == 1 || x == 2 || x == 3)
      return 1;
    for (int i = 0; i <= x; i++) {
      mult = i * i;
      if (mult == x)
        return i;
      else if (mult > x)
        return i - 1;
    }
    return 0;
  }
  int mySqrt2(int x) {
    if (x <= 1)
      return x;
    int left = 0, right = x;
    while (left < right) {
      int mid = left + (right - left) / 2;
      if (x / mid >= mid)
        left = mid + 1;
      else
        right = mid;
    }
    return right - 1;
  }
  int mySqrt(int x) {
    long res = x;
    while (res * res > x) {
      res = (res + x / res) / 2;
    }
    return res;
  }
};
