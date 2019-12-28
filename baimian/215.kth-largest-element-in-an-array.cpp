/*
 * @lc app=leetcode id=215 lang=cpp
 *
 * [215] Kth Largest Element in an Array
 *
 * https://leetcode.com/problems/kth-largest-element-in-an-array/description/
 *
 * algorithms
 * Medium (49.22%)
 * Likes:    2291
 * Dislikes: 188
 * Total Accepted:    417.2K
 * Total Submissions: 846.7K
 * Testcase Example:  '[3,2,1,5,6,4]\n2'
 *
 * Find the kth largest element in an unsorted array. Note that it is the kth
 * largest element in the sorted order, not the kth distinct element.
 * 
 * Example 1:
 * 
 * 
 * Input: [3,2,1,5,6,4] and k = 2
 * Output: 5
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [3,2,3,1,2,4,5,5,6] and k = 4
 * Output: 4
 * 
 * Note: 
 * You may assume k is always valid, 1 ≤ k ≤ array's length.
 * 
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution
{
public:
    int partition(vector<int> &nums, int left, int right)
    {
        int pliot = nums[right];
        int curr = left;
        for (int i = left; i < right; i++)
        {
            if (nums[i] > pliot)
            {
                swap(nums[curr], nums[i]);
                curr++;
            }
        }
        swap(nums[curr], nums[right]);
        return curr;
    }
    void quickSort(vector<int> &nums, int left, int right)
    {
        if (left < right)
        {
            int p = partition(nums, left, right);
            quickSort(nums, left, p - 1);
            quickSort(nums, p + 1, right);
        }
    }

    void HeapAdjust(vector<int> &nums, int length, int k)
    {
        int tmp = nums[k];
        int i = 2 * k + 1;
        while (i < length)
        {
            if (i + 1 < length && nums[i] > nums[i + 1]) //选取最小的结点位置
                ++i;
            if (tmp < nums[i]) //不用交换
                break;
            nums[k] = nums[i]; //交换值
            k = i;             //继续查找
            i = 2 * k + 1;
        }
        nums[k] = tmp;
    }

    void HeapSort(vector<int> &nums, int length)
    {
        if (nums.size() == NULL || length <= 0)
            return;
        for (int i = length / 2 - 1; i >= 0; --i)
        {
            HeapAdjust(nums, length, i); //从第二层开始建堆
        }

        for (int i = length - 1; i >= 0; --i)
        {
            std::swap(nums[0], nums[i]);
            HeapAdjust(nums, i, 0); //从顶点开始建堆, 忽略最后一个
        }

        return;
    }
    int findKthLargest(vector<int> &nums, int k)
    {
        HeapSort(nums, nums.size());
        return nums[k - 1];
    }
    int findKthLargest_quicksort(vector<int> &nums, int k)
    {
        quickSort(nums, 0, nums.size() - 1);
        return nums[k - 1];
    }
    int findKthLargest_cheat(vector<int> &nums, int k)
    {
        sort(nums.begin(), nums.end(), [](int a, int b) {
            return a > b;
        });
        return nums[k - 1];
    }
};
