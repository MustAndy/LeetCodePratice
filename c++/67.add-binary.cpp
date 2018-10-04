/*
 * [67] Add Binary
 *
 * https://leetcode.com/problems/add-binary/description/
 *
 * algorithms
 * Easy (35.70%)
 * Total Accepted:    231.5K
 * Total Submissions: 648.4K
 * Testcase Example:  '"11"\n"1"'
 *
 * Given two binary strings, return their sum (also a binary string).
 *
 * The input strings are both non-empty and contains only characters 1 or 0.
 *
 * Example 1:
 *
 *
 * Input: a = "11", b = "1"
 * Output: "100"
 *
 * Example 2:
 *
 *
 * Input: a = "1010", b = "1011"
 * Output: "10101"
 *
 */

#include <iostream>
using namespace std;

class Solution
{
  public:
    string addBinary(string a, string b)
    {
        string result;
        int length = a.size() > b.size() ? a.size() : b.size();
        bool aLongerB = a.size() > b.size() ? true : false;
        int aint[length], bint[length];
        int adder = 0, tempResult;

        for (int i = 0; i < length + 1; i++)
        {

            if ((a.size() != 0) && (b.size() != 0))
            {
                string::iterator aend = --a.end();
                string::iterator bend = --b.end();

                tempResult = (*aend - '0') + (*bend - '0') + adder;

                a.pop_back();
                b.pop_back();
            }
            else if (a.size() != 0)
            {
                string::iterator aend = --a.end();
                tempResult = (*aend - '0') + adder;
                a.pop_back();
            }
            else if (b.size() != 0)
            {
                string::iterator bend = --b.end();
                tempResult = (*bend - '0') + adder;
                b.pop_back();
            }
            else if (adder == 1)
            {
                tempResult = adder;
            }
            else
            {
                break;
            }
            cout << tempResult << endl;
            switch (tempResult)
            {
            case 0:
                result.insert(0, "0");
                // result += "0";
                adder = 0;
                break;
            case 1:
                // result += "0";
                result.insert(0, "1");
                adder = 0;
                break;

            case 2:
                result.insert(0, "0");
                // result += "0";
                adder = 1;
                break;
            case 3:
                result.insert(0, "1");
                // result += "0";
                adder = 1;
                break;
            }
        }

        return result;
    }
};