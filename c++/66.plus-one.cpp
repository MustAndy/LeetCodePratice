/*
 * [66] Plus One
 *
 * https://leetcode.com/problems/plus-one/description/
 *
 * algorithms
 * Easy (40.00%)
 * Total Accepted:    287.6K
 * Total Submissions: 719K
 * Testcase Example:  '[1,2,3]'
 *
 * Given a non-empty array of digits representing a non-negative integer, plus
 * one to the integer.
 *
 * The digits are stored such that the most significant digit is at the head of
 * the list, and each element in the array contain a single digit.
 *
 * You may assume the integer does not contain any leading zero, except the
 * number 0 itself.
 *
 * Example 1:
 *
 *
 * Input: [1,2,3]
 * Output: [1,2,4]
 * Explanation: The array represents the integer 123.
 *
 *
 * Example 2:
 *
 *
 * Input: [4,3,2,1]
 * Output: [4,3,2,2]
 * Explanation: The array represents the integer 4321.
 *
 *
 */

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution
{
  public:
    vector<int> plusOne1(vector<int> &digits)
    {
        vector<int> result, temp;
        int adder = 0;
        int limits;

        digits[(digits.size() - 1)]++;

        for (int i = digits.size() - 1; i >= 1; i--)
        {
            digits[i] += adder;
            adder = 0;
            if ((digits[i]) == 10)
            {
                digits[i] = 0;
                temp.push_back(0);
                adder++;
                continue;
            }
            temp.push_back(digits[i]);
        }
        if (((digits[0] == 9) && (adder == 1)) || (digits[0] == 10))
        {
            temp.push_back(0);
            temp.push_back(1);
        }
        else
            temp.push_back(digits[0] + adder);

        // for (int i = temp.size() - 1; i >= 0; i--)
        // {
        //     result.push_back(temp[i]);
        // }
        reverse(temp.begin(), temp.end());
        return temp;
    }
    vector<int> plusOne(vector<int> &digits)
    {
        int i = digits.size() - 1;
        int sum = 1;
        int carry = 0;

        while (i >= 0)
        {
            sum += carry + digits[i];
            digits[i--] = sum % 10;
            carry = sum / 10;
            sum = 0;
        }

        if (carry > 0)
            digits.insert(digits.begin(), carry);

        return digits;
    }
};
