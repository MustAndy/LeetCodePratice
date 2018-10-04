/*
 * @Author: AndyWong 
 * @Date: 2018-09-19 16:56:23 
 * @Last Modified by: AndyWong
 * @Last Modified time: 2018-09-19 16:57:00
 */
/*
 * [13] Roman to Integer
 *
 * https://leetcode.com/problems/roman-to-integer/description/
 *
 * algorithms
 * Easy (49.37%)
 * Total Accepted:    276.3K
 * Total Submissions: 559.6K
 * Testcase Example:  '"III"'
 *
 * Roman numerals are represented by seven different symbols: I, V, X, L, C, D
 * and M.
 *
 *
 * Symbol       Value
 * I             1
 * V             5
 * X             10
 * L             50
 * C             100
 * D             500
 * M             1000
 */

/*
 *
 * For example, two is written as II in Roman numeral, just two one's added
 * together. Twelve is written as, XII, which is simply X + II. The number
 * twenty seven is written as XXVII, which is XX + V + II.
 *
 * Roman numerals are usually written largest to smallest from left to right.
 * However, the numeral for four is not IIII. Instead, the number four is
 * written as IV. Because the one is before the five we subtract it making
 * four. The same principle applies to the number nine, which is written as IX.
 * There are six instances where subtraction is used:
 *
 *
 * I can be placed before V (5) and X (10) to make 4 and 9. 
 * X can be placed before L (50) and C (100) to make 40 and 90. 
 * C can be placed before D (500) and M (1000) to make 400 and 900.
 *
 *
 * Given a roman numeral, convert it to an integer. Input is guaranteed to be
 * within the range from 1 to 3999.
 *
 * Example 1:
 *
 *
 * Input: "III"
 * Output: 3
 *
 * Example 2:
 *
 *
 * Input: "IV"
 * Output: 4
 *
 * Example 3:
 *
 *
 * Input: "IX"
 * Output: 9
 *
 * Example 4:
 *
 *
 * Input: "LVIII"
 * Output: 58
 * Explanation: C = 100, L = 50, XXX = 30 and III = 3.
 *
 *
 * Example 5:
 *
 *
 * Input: "MCMXCIV"
 * Output: 1994
 * Explanation: M = 1000, CM = 900, XC = 90 and IV = 4.
 *
 */

enum
{
    I = 1,
    V = 5,
    X = 10,
    L = 50,
    C = 100,
    D = 500,
    M = 1000
};
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution
{
  public:
    int findElement(vector<int> temp, int target)
    {
        for (int i = 0; i < temp.size(); i++)
        {
            if (temp[i] == target)
                return i;
        }
        return -1;
    }

    int romanToInt(string s)
    {
        int result = 0;
        vector<int> temp;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == 'I')
                temp.push_back(1);
            if (s[i] == 'V')
                temp.push_back(5);
            if (s[i] == 'X')
                temp.push_back(10);
            if (s[i] == 'L')
                temp.push_back(50);
            if (s[i] == 'C')
                temp.push_back(100);
            if (s[i] == 'D')
                temp.push_back(500);
            if (s[i] == 'M')
                temp.push_back(1000);
        }
        char priority[7] = {'M', 'D', 'C', 'L', 'X', 'V', 'I'};
        int prior[7] = {M, D, C, L, X, V, I};
        // for (int i = 0; i < temp.size(); i++)
        // cout << temp[i] << endl;
        for (int i = 0; i < 7; i++)
        {
            int marks = 1;
            while (1)
            {
                marks = findElement(temp, prior[i]);
                // cout << marks << endl;
                if (marks != -1) // found the letter.
                {
                    int tempSum = 0;
                    tempSum += temp[marks];
                    marks--; // give the letter to the tempsum and check if the left side
                             // has any letter.

                    if (marks == -1) // first letter is the matched letter.
                    {
                        result += tempSum;
                        temp[0] = 0;
                        continue;
                    }
                    else // the rest of letter is the matched letter
                    {
                        while (marks != -1 && temp[marks] != 0)
                        {

                            tempSum -= temp[marks];
                            temp[marks] = 0;
                            temp[marks + 1] = 0;
                            marks--;
                        }
                        if (temp[marks] == 0)
                        {
                            result += tempSum;

                            temp[marks + 1] = 0;
                            // for (int i = 1; i < temp.size(); i++)
                            // {

                            //     if (temp[i] == temp[i - 1])
                            //     {
                            //     }
                            //     if ((temp[i - 1] < temp[i]) &&
                            //         (temp[i - 1] == 1 || temp[i - 1] == 10 || temp[i - 1]
                            //         == 100))
                            //     {
                            //     }
                            //     if ((temp[i] > temp[i + 1]) &&
                            //         (temp[i + 1] == 1 || temp[i + 1] == 10 || temp[i + 1]
                            //         == 100))
                            //     {
                            //     }
                            // }
                            continue;
                        }
                    }
                }
                else
                    break;
            }
        }

        return result;
    }
};