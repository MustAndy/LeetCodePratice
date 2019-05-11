/*
 * @lc app=leetcode id=179 lang=cpp
 *
 * [179] Largest Number
 *
 * https://leetcode.com/problems/largest-number/description/
 *
 * algorithms
 * Medium (24.91%)
 * Total Accepted:    115.9K
 * Total Submissions: 465.1K
 * Testcase Example:  '[10,2]'
 *
 * Given a list of non negative integers, arrange them such that they form the
 * largest number.
 * 
 * Example 1:
 * 
 * 
 * Input: [10,2]
 * Output: "210"
 * 
 * Example 2:
 * 
 * 
 * Input: [3,30,34,5,9]
 * Output: "9534330"
 * 
 * 
 * Note: The result may be very large, so you need to return a string instead
 * of an integer.
 * 
 */
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
class Solution
{
  public:
    static bool cmp(string a, string b)
    {
        return a + b > b + a;
    }
    string largestNumber(vector<int> &nums)
    {
        vector<string> arr; //定义一个string容器
        for (auto i : nums) // 需要将int容器里的每一个数字转化为string
            arr.push_back(to_string(i));
        // 对string里的元素排序，依据是 任意两个string连接之后
        sort(begin(arr), end(arr), cmp);
        string res; // 存放结果
        for (auto s : arr)
            res += s;                             // 将结果进行连接起来
        while (res[0] == '0' && res.length() > 1) // 对特殊情况的处理
            res.erase(0, 1);                      //每次删除第一位的0，注意erase的用法
        return res;
    }
};
