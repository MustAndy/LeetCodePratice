/*
 * @Author: AndyWong
 * @Date: 2018-10-04 23:43:38
 * @Last Modified by:   AndyWong
 * @Last Modified time: 2018-10-04 23:43:38
 */
/*
 * [342] Power of Four
 *
 * https://leetcode.com/problems/power-of-four/description/
 *
 * algorithms
 * Easy (39.56%)
 * Total Accepted:    96.2K
 * Total Submissions: 243K
 * Testcase Example:  '16'
 *
 * Given an integer (signed 32 bits), write a function to check whether it is a
 * power of 4.
 *
 * Example 1:
 *
 *
 * Input: 16
 * Output: true
 *
 *
 *
 * Example 2:
 *
 *
 * Input: 5
 * Output: false
 *
 *
 * Follow up: Could you solve it without loops/recursion?
 *
 */

#include <algorithm>
#include <math.h>
using namespace std;
class Solution {
public:
  bool isPowerOfFour(int n) {
    return (n > 0 && int(log10(n) / log10(4)) - log10(n) / log10(4) == 0);
  }
};
