/*
 * @lc app=leetcode id=504 lang=cpp
 *
 * [504] Base 7
 *
 * https://leetcode.com/problems/base-7/description/
 *
 * algorithms
 * Easy (45.07%)
 * Likes:    158
 * Dislikes: 121
 * Total Accepted:    43.6K
 * Total Submissions: 96.8K
 * Testcase Example:  '100'
 *
 * Given an integer, return its base 7 string representation.
 * 
 * Example 1:
 * 
 * Input: 100
 * Output: "202"
 * 
 * 
 * 
 * Example 2:
 * 
 * Input: -7
 * Output: "-10"
 * 
 * 
 * 
 * Note:
 * The input will be in range of [-1e7, 1e7].
 * 
 */
#include <string>
using namespace std;
class Solution
{
public:
    string convertToBase7(int num)
    {
        if (num < 0)
            return "-" + convertToBase7(-num);
        if (num < 7)
            return to_string(num);
        return convertToBase7(num / 7) + to_string(num % 7);
    }
};
