/*
 * [119] Pascal's Triangle II
 *
 * https://leetcode.com/problems/pascals-triangle-ii/description/
 *
 * algorithms
 * Easy (40.05%)
 * Total Accepted:    163.9K
 * Total Submissions: 409.2K
 * Testcase Example:  '3'
 *
 * Given a non-negative index k where k ≤ 33, return the kth index row of the
 * Pascal's triangle.
 *
 * Note that the row index starts from 0.
 *
 *
 * In Pascal's triangle, each number is the sum of the two numbers directly
 * above it.
 *
 * Example:
 *
 *
 * Input: 3
 * Output: [1,3,3,1]
 *
 *
 * Follow up:
 *
 * Could you optimize your algorithm to use only O(k) extra space?
 *
 *
 * 这道题主要要抓住杨辉三角形的特性，可用的特性主要是第n行的第k个数字为组合数C_{n-1}^{k-1}。
 *
 * 以及除每行最左侧与最右侧的数字以外，每个数字等于它的左上方与右上方两个数字之和（也就是说，第n行第k个数字等于第n-1行的第k-1个数字与第k个数字的和）。
 * 这是因为有组合恒等式：C_{n}^{i}=C_{n-1}^{i-1}+C_{n-1}^{i}。可用此性质写出整个杨辉三角形。
 *
 *
 */
#include <iostream>
#include <vector>
using namespace std;
class Solution
{
  public:
    vector<int> getRow(int rowIndex)
    {
        vector<int> result;
        if (rowIndex < 0)
            return result;

        result.assign(rowIndex + 1, 0);

        for (int i = 0; i <= rowIndex; ++i)
        {
            if (i == 0)
            {
                result[0] = 1;
                continue;
            }
            for (int j = rowIndex; j >= 1; --j)
            {
                result[j] = result[j - 1] + result[j];
            }
        }

        return result;
    }

    int CountSum(int n, int k)
    {
        if (k > n)
            return 0;
        else if (k > n / 2)
            k = n - k;
        int numerator = 1, denomator = 1;
        for (int i = 0; i < k; ++i)
        {
            numerator *= n - i;
            denomator *= k - i;
        }
        if (denomator != 0)
            return numerator / denomator;
        else
            return 0;
    }
};
