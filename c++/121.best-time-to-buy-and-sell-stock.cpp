/*
 * @lc app=leetcode id=121 lang=cpp
 *
 * [121] Best Time to Buy and Sell Stock
 */
class Solution
{
public:
    int maxProfit1(vector<int> &prices)
    {
        int length = prices.size();
        int smallest = 0, biggest = 0, sum = 0;
        for (int i = 0; i < length; ++i)
        {
            for (int j = i; j < length; ++j)
            {
                if (prices[j] - prices[i] > sum)
                {
                    sum = prices[j] - prices[i];
                    smallest = i;
                    biggest = j;
                }
            }
        }

        return sum;
    }
    int maxProfit(vector<int> &prices)
    {
        int maxPro = 0;
        int length = prices.size();
        int minPrice = INT_MAX;
        for (int i = 0; i < length; i++)
        {
            minPrice = min(minPrice, prices[i]);
            maxPro = max(maxPro, prices[i] - minPrice);
        }
        return maxPro;
    }
};
