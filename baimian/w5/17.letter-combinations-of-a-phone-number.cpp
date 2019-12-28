/*
 * @lc app=leetcode id=17 lang=cpp
 *
 * [17] Letter Combinations of a Phone Number
 *
 * https://leetcode.com/problems/letter-combinations-of-a-phone-number/description/
 *
 * algorithms
 * Medium (42.63%)
 * Likes:    2509
 * Dislikes: 331
 * Total Accepted:    435.1K
 * Total Submissions: 1M
 * Testcase Example:  '"23"'
 *
 * Given a string containing digits from 2-9 inclusive, return all possible
 * letter combinations that the number could represent.
 * 
 * A mapping of digit to letters (just like on the telephone buttons) is given
 * below. Note that 1 does not map to any letters.
 * 
 * 
 * 
 * Example:
 * 
 * 
 * Input: "23"
 * Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
 * 
 * 
 * Note:
 * 
 * Although the above answer is in lexicographical order, your answer could be
 * in any order you want.
 * 
 */
#include <vector>
#include <string>
using namespace std;
class Solution
{
public:
    vector<string> letterCombinations(string digits)
    {
        vector<string> res;
        if (digits.empty())
            return res;
        vector<string> letter({"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"});
        string path = "";
        DFS(digits, 0, path, res, letter);
        return res;
    }
    void DFS(string digits, int pos, string &path, vector<string> &res, vector<string> &letter)
    {
        if (pos == digits.size())
        {
            res.push_back(path);
            return;
        }
        for (auto charater : letter[digits[pos] - '0'])
        {
            path.push_back(charater);
            DFS(digits, pos + 1, path, res, letter);
            path.pop_back();
        }
    }
};
