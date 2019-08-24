/*
 * @lc app=leetcode id=347 lang=cpp
 *
 * [347] Top K Frequent Elements
 *
 * https://leetcode.com/problems/top-k-frequent-elements/description/
 *
 * algorithms
 * Medium (56.10%)
 * Likes:    1744
 * Dislikes: 111
 * Total Accepted:    232.6K
 * Total Submissions: 414.2K
 * Testcase Example:  '[1,1,1,2,2,3]\n2'
 *
 * Given a non-empty array of integers, return the k most frequent elements.
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [1,1,1,2,2,3], k = 2
 * Output: [1,2]
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [1], k = 1
 * Output: [1]
 * 
 * 
 * Note: 
 * 
 * 
 * You may assume k is always valid, 1 ≤ k ≤ number of unique elements.
 * Your algorithm's time complexity must be better than O(n log n), where n is
 * the array's size.
 * 
 * 
 */
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;
class Solution
{
public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        int length = nums.size();
        unordered_map<int, int> mapping;
        for (int num : nums)
        {
            mapping[num]++;
        }
        vector<int> result;
        vector<pair<int, int>> pq;
        unordered_map<int, int>::iterator iter;
        int i = 0;
        for (iter = mapping.begin(); iter != mapping.end(); iter++)
        {
            pq.push_back(make_pair(iter->second, iter->first));
        }
        sort(pq.begin(), pq.end(), [](pair<int, int> a, pair<int, int> b) {
            return a.first > b.first;
        });

        for (int i = 0; i < k; i++)
        {
            result.push_back(pq[i].second);
        }

        return result;
    }
};
