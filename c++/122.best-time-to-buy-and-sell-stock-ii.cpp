/*
 * @lc app=leetcode id=122 lang=cpp
 *
 * [122] Best Time to Buy and Sell Stock II
 */
#include <vector>
#include <iostream>
#include <limits.h>
using namespace std;
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int maxPro = 0;
        if (prices.size() == 0)
            return 0;
        int length = prices.size();

        for (int i = 0; i < length - 1; i++)
        {
            maxPro += max(0, prices[i + 1] - prices[i]);
        }
        return maxPro;
    }
};
