/*
 * @lc app=leetcode id=378 lang=cpp
 *
 * [378] Kth Smallest Element in a Sorted Matrix
 *
 * https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/description/
 *
 * algorithms
 * Medium (50.39%)
 * Likes:    1402
 * Dislikes: 89
 * Total Accepted:    124.5K
 * Total Submissions: 246.5K
 * Testcase Example:  '[[1,5,9],[10,11,13],[12,13,15]]\n8'
 *
 * Given a n x n matrix where each of the rows and columns are sorted in
 * ascending order, find the kth smallest element in the matrix.
 * 
 * 
 * Note that it is the kth smallest element in the sorted order, not the kth
 * distinct element.
 * 
 * 
 * Example:
 * 
 * matrix = [
 * ⁠  [ 1,  5,  9],
 * ⁠  [10, 11, 13],
 * ⁠  [12, 13, 15]
 * ],
 * k = 8,
 * 
 * return 13.
 * 
 * 
 * 
 * Note: 
 * You may assume k is always valid, 1 ≤ k ≤ n^2.
 */
#include <vector>
#include <queue>
using namespace std;

#include <algorithm>
class Solution
{
public:
    int kthSmallest_minheap(vector<vector<int>> &matrix, int k)
    {
        priority_queue<int, vector<int>, greater<int>> pq;
        for (auto x : matrix)
            for (auto y : x)
                pq.push(y);
        while (--k)
            pq.pop();
        return pq.top();
    }
    int kthSmallest(vector<vector<int>> &matrix, int k)
    {

        int m = matrix.size(), n = matrix[0].size();

        vector<int> nums_vec;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                nums_vec.push_back(matrix[i][j]);
            }
        }
        sort(nums_vec.begin(), nums_vec.end());
        return nums_vec[k - 1];
    }
};
