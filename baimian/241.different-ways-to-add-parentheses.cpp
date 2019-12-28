/*
 * @lc app=leetcode id=241 lang=cpp
 *
 * [241] Different Ways to Add Parentheses
 *
 * https://leetcode.com/problems/different-ways-to-add-parentheses/description/
 *
 * algorithms
 * Medium (51.14%)
 * Likes:    1062
 * Dislikes: 53
 * Total Accepted:    79.9K
 * Total Submissions: 156K
 * Testcase Example:  '"2-1-1"'
 *
 * Given a string of numbers and operators, return all possible results from
 * computing all the different possible ways to group numbers and operators.
 * The valid operators are +, - and *.
 * 
 * Example 1:
 * 
 * 
 * Input: "2-1-1"
 * Output: [0, 2]
 * Explanation: 
 * ((2-1)-1) = 0 
 * (2-(1-1)) = 2
 * 
 * Example 2:
 * 
 * 
 * Input: "2*3-4*5"
 * Output: [-34, -14, -10, -10, 10]
 * Explanation: 
 * (2*(3-(4*5))) = -34 
 * ((2*3)-(4*5)) = -14 
 * ((2*(3-4))*5) = -10 
 * (2*((3-4)*5)) = -10 
 * (((2*3)-4)*5) = 10
 * 
 */
#include <vector>
using namespace std;
#include <string>
class Solution
{
public:
    vector<int> diffWaysToCompute(string input)
    {
        vector<int> result;
        int length = input.size();
        for (int i = 0; i < length; ++i)
        {
            char cur = input[i];
            if (cur == '+' || cur == '-' || cur == '*')
            {
                vector<int> result1 = diffWaysToCompute(input.substr(0, i));
                vector<int> result2 = diffWaysToCompute(input.substr(i + 1));
                for (int n1 : result1)
                {
                    for (int n2 : result2)
                    {
                        if (cur == '+')
                            result.push_back(n1 + n2);
                        else if (cur == '-')
                            result.push_back(n1 - n2);
                        else
                            result.push_back(n1 * n2);
                    }
                }
            }
        }
        if (result.empty())
            result.push_back(atoi(input.c_str()));
        return result;
    }
};
