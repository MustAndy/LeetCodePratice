/*
 * [137] Single Number II
 *
 * https://leetcode.com/problems/single-number-ii/description/
 *
 * algorithms
 * Medium (43.78%)
 * Total Accepted:    144.9K
 * Total Submissions: 330.9K
 * Testcase Example:  '[2,2,3,2]'
 *
 * Given a non-empty array of integers, every element appears three times
 * except for one, which appears exactly once. Find that single one.
 *
 * Note:
 *
 * Your algorithm should have a linear runtime complexity. Could you implement
 * it without using extra memory?
 *
 * Example 1:
 *
 *
 * Input: [2,2,3,2]
 * Output: 3
 *
 *
 * Example 2:
 *
 *
 * Input: [0,1,0,1,0,1,99]
 * Output: 99
 *
 *
 * 思路是抓住一个：00->01->10->00
 * 用a和b来代表两个bits
 * 最终留下的b就是那个只出现了一次的number
 *
 */
#include <vector>
using namespace std;
#include <iostream>
class Solution {
public:
  int singleNumber(vector<int> &nums) {
    int a = 0, b = 0;
    for (int i = 0; i < nums.size(); ++i) {
      b = (b ^ nums[i]) & ~a;
      a = (a ^ nums[i]) & ~b;
      cout << a << " " << b << endl;
    }
    return b;
  }
};
