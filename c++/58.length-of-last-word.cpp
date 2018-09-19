/*
 * [58] Length of Last Word
 *
 * https://leetcode.com/problems/length-of-last-word/description/
 *
 * algorithms
 * Easy (32.09%)
 * Total Accepted:    212K
 * Total Submissions: 660.6K
 * Testcase Example:  '"Hello World"'
 *
 * Given a string s consists of upper/lower-case alphabets and empty space
 * characters ' ', return the length of last word in the string.
 *
 * If the last word does not exist, return 0.
 *
 * Note: A word is defined as a character sequence consists of non-space
 * characters only.
 *
 * Example:
 *
 * Input: "Hello World"
 * Output: 5
 *
 *
 */
#include <iostream>
#include <string>
using namespace std;

class Solution
{
  public:
    int lengthOfLastWord(string s)
    {
        if (s.length() == 0)
            return 0;

        int length = s.length() - 1;
        int counter = 0;
        int i = length;
        while (s[i] == 32 && i != -1)
        {
            i--;
        }

        for (i; i >= 0; i--)
        {

            if (s[i] != 32)
                counter++;
            if (s[i] == 32)
                break;
        }
        return counter;
    }
};
