/*
 * @Author: AndyWong 
 * @Date: 2018-09-19 16:56:45 
 * @Last Modified by:   AndyWong 
 * @Last Modified time: 2018-09-19 16:56:45 
 */
/*
 * [6] ZigZag Conversion
 *
 * https://leetcode.com/problems/zigzag-conversion/description/
 *
 * algorithms
 * Medium (28.48%)
 * Total Accepted:    235.4K
 * Total Submissions: 826.6K
 * Testcase Example:  '"PAYPALISHIRING"\n3'
 *
 * The string "PAYPALISHIRING" is written in a zigzag pattern on a given number
 * of rows like this: (you may want to display this pattern in a fixed font for
 * better legibility)
 *

 *
 * P   A   H   N
 * A P L S I I G
 * Y   I   R
 *
 *
 * And then read line by line: "PAHNAPLSIIGYIR"
 *
 * Write the code that will take a string and make this conversion given a
 * number of rows:
 *
 *
 * string convert(string s, int numRows);
 *
 * Example 1:
 *
 *
 * Input: s = "
 * PAYP
 * ALIS
 * HIRI
 * NG", numRows = 3
 * Output: "PAHNAPLSIIGYIR"
 *
 *
 * Example 2:
 *
 *
 * Input: s = "PAYPAL
 *             ISHIRI
 *             NG", numRows = 4
 * Output: "PINALSIGYAHRPI"
 * Explanation:
 *
 * P     I    N
 * A   L S  I G
 * Y A   H R
 * P     I
 *
 */
#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Solution
{
  public:
    string convert(string s, int nRows)
    {
        if (nRows == 1)
            return s;
        int len = s.size(), k = 0, interval = (nRows << 1) - 2;
        string res(len, ' ');
        for (int j = 0; j < len; j += interval) //处理第一行
            res[k++] = s[j];
        for (int i = 1; i < nRows - 1; i++) //处理中间行
        {
            int inter = (i << 1);
            for (int j = i; j < len; j += inter)
            {
                res[k++] = s[j];
                inter = interval - inter;
            }
        }
        for (int j = nRows - 1; j < len; j += interval) //处理最后一行
            res[k++] = s[j];
        return res;
    }
};