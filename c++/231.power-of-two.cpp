/*
 * @Author: AndyWong
 * @Date: 2018-10-04 23:43:26
 * @Last Modified by:   AndyWong
 * @Last Modified time: 2018-10-04 23:43:26
 */
/*
 * [231] Power of Two
 *
 * https://leetcode.com/problems/power-of-two/description/
 *
 * algorithms
 * Easy (41.13%)
 * Total Accepted:    192K
 * Total Submissions: 466.7K
 * Testcase Example:  '1'
 *
 * Given an integer, write a function to determine if it is a power of two.
 *
 * Example 1:
 *
 *
 * Input: 1
 * Output: true
 * Explanation: 20 = 1
 *
 *
 * Example 2:
 *
 *
 * Input: 16
 * Output: true
 * Explanation: 24 = 16
 *
 * Example 3:
 *
 *
 * Input: 218
 * Output: false
 *
 */
#include <algorithm>
#include <math.h>
using namespace std;
class Solution {
public:
  bool isPowerOfTwo(int n) {
    return (n > 0 && int(log10(n) / log10(2)) - log10(n) / log10(2) == 0);
  }
};