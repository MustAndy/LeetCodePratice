/*
 * [9] Palindrome Number
 *
 * https://leetcode.com/problems/palindrome-number/description/
 *
 * algorithms
 * Easy (38.13%)
 * Total Accepted:    386.4K
 * Total Submissions: 1M
 * Testcase Example:  '121'
 *
 * Determine whether an integer is a palindrome. An integer is a palindrome
 * when it reads the same backward as forward.
 * 
 * Example 1:
 * 
 * 
 * Input: 121
 * Output: true
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: -121
 * Output: false
 * Explanation: From left to right, it reads -121. From right to left, it
 * becomes 121-. Therefore it is not a palindrome.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: 10
 * Output: false
 * Explanation: Reads 01 from right to left. Therefore it is not a
 * palindrome.
 * 
 * 
 * Follow up:
 * 
 * Coud you solve it without converting the integer to a string?
 * 
 */
#include <limits.h>
#include <iostream>
using namespace std;

class Solution
{
  public:
    int reverse(int x)
    {
        bool isNegi = false;
        if (x < 0)
        {
            x *= -1;
            isNegi = true;
        }
        int result = 0;
        while (x != 0)
        {
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
    bool isPalindrome(int x)
    {
        if (x < 0)
            return false;
        int temp = reverse(x);
        if (temp == x)
            return true;
        else
            return false;
    }
};
