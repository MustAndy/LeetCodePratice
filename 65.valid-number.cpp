/*
 * @lc app=leetcode id=65 lang=cpp
 *
 * [65] Valid Number
 *
 * https://leetcode.com/problems/valid-number/description/
 *
 * algorithms
 * Hard (14.24%)
 * Likes:    492
 * Dislikes: 3531
 * Total Accepted:    133.4K
 * Total Submissions: 934.9K
 * Testcase Example:  '"0"'
 *
 * Validate if a given string can be interpreted as a decimal number.
 * 
 * Some examples:
 * "0" => true
 * " 0.1 " => true
 * "abc" => false
 * "1 a" => false
 * "2e10" => true
 * " -90e3   " => true
 * " 1e" => false
 * "e3" => false
 * " 6e-1" => true
 * " 99e2.5 " => false
 * "53.5e93" => true
 * " --6 " => false
 * "-+3" => false
 * "95a54e53" => false
 * 
 * Note: It is intended for the problem statement to be ambiguous. You should
 * gather all requirements up front before implementing one. However, here is a
 * list of characters that can be in a valid decimal number:
 * 
 * 
 * Numbers 0-9
 * Exponent - "e"
 * Positive/negative sign - "+"/"-"
 * Decimal point - "."
 * 
 * 
 * Of course, the context of these characters also matters in the input.
 * 
 * Update (2015-02-10):
 * The signature of the C++ function had been updated. If you still see your
 * function signature accepts a const char * argument, please click the reload
 * button to reset your code definition.
 * 
 */
#include <string>
#include <stdio.h>
using namespace std;
class Solution
{
private:
    bool isSpace(char c) { return c == ' '; }
    bool isSgn(char c) { return c == '+' || c == '-'; }
    bool isDot(char c) { return c == '.'; }
    bool isNum(char c) { return c <= '9' && c >= '0'; }
    bool isE(char c) { return c == 'e' || c == 'E'; }

public:
    bool isNumber(string s)
    {
        int pos = 0;
        bool haveNum = false;

        // Check all the prefix spaces
        while (pos < s.size() && isSpace(s[pos]))
            pos++;

        // Check the next char if it's a +/- signal
        if (pos < s.size() && isSgn(s[pos]))
            pos++;

        // Check the numbers before a dot '.'
        while (pos < s.size() && isNum(s[pos]))
        {
            haveNum = true;
            pos++;
        }

        // Check the dot '.'
        if (pos < s.size() && isDot(s[pos]))
            pos++;

        // Check the numbers after a dot '.'
        while (pos < s.size() && isNum(s[pos]))
        {
            haveNum = true;
            pos++;
        }

        // Check the 'e' / 'E'
        if (haveNum && pos < s.size() && isE(s[pos]))
        {
            haveNum = false;
            pos++;
            if (pos < s.size() && isSgn(s[pos]))
                pos++;
        }

        // Check the numbers after 'e' / 'E'
        while (pos < s.size() && isNum(s[pos]))
        {
            haveNum = true;
            pos++;
        }

        // Check all the remaining spaces
        while (pos < s.size() && isSpace(s[pos]))
            pos++;

        // Everything is done, if the string not empty, return false.
        return (pos == s.size() && haveNum);
    }
};