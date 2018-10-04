/*
 * @Author: AndyWong
 * @Date: 2018-10-04 23:43:32
 * @Last Modified by:   AndyWong
 * @Last Modified time: 2018-10-04 23:43:32
 */
/*
 * [326] Power of Three
 *
 * https://leetcode.com/problems/power-of-three/description/
 *
 * algorithms
 * Easy (40.96%)
 * Total Accepted:    147.7K
 * Total Submissions: 360.5K
 * Testcase Example:  '27'
 *
 * Given an integer, write a function to determine if it is a power of three.
 *
 * Example 1:
 *
 *
 * Input: 27
 * Output: true
 *
 *
 * Example 2:
 *
 *
 * Input: 0
 * Output: false
 *
 * Example 3:
 *
 *
 * Input: 9
 * Output: true
 *
 * Example 4:
 *
 *
 * Input: 45
 * Output: false
 *
 * Follow up:
 * Could you do it without using any loop / recursion?
 *
 */
#include <algorithm>
#include <math.h>
using namespace std;
class Solution {
public:
  bool isPowerOfThree(int n) {
    return (n > 0 && int(log10(n) / log10(3)) - log10(n) / log10(3) == 0);
  }
};
