/*
 * @lc app=leetcode id=303 lang=cpp
 *
 * [303] Range Sum Query - Immutable
 *
 * https://leetcode.com/problems/range-sum-query-immutable/description/
 *
 * algorithms
 * Easy (39.26%)
 * Likes:    539
 * Dislikes: 842
 * Total Accepted:    153.8K
 * Total Submissions: 387.6K
 * Testcase Example:  '["NumArray","sumRange","sumRange","sumRange"]\n[[[-2,0,3,-5,2,-1]],[0,2],[2,5],[0,5]]'
 *
 * Given an integer array nums, find the sum of the elements between indices i
 * and j (i ≤ j), inclusive.
 * 
 * Example:
 * 
 * Given nums = [-2, 0, 3, -5, 2, -1]
 * 
 * sumRange(0, 2) -> 1
 * sumRange(2, 5) -> -1
 * sumRange(0, 5) -> -3
 * 
 * 
 * 
 * Note:
 * 
 * You may assume that the array does not change.
 * There are many calls to sumRange function.
 * 
 * 
 */
#include <vector>
using namespace std;
class NumArray
{
private:
    vector<int> result;

public:
    NumArray(vector<int> &nums)
    {
        result = nums;
    }

    int sumRange(int i, int j)
    {
        int resultNum = 0;
        for (i; i <= j; i++)
            resultNum += result[i];
        return resultNum;
    }
};
class NumArray
{
public:
    NumArray(vector<int> &nums)
    {
        accu.push_back(0);
        for (int num : nums)
            accu.push_back(accu.back() + num);
    }

    int sumRange(int i, int j)
    {
        return accu[j + 1] - accu[i];
    }

private:
    vector<int> accu;
};
/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */
