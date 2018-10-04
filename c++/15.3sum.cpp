/*
 * @Author: AndyWong
 * @Date: 2018-09-19 16:56:13
 * @Last Modified by: AndyWong
 * @Last Modified time: 2018-09-19 16:57:01
 */
/*  du du du du du du du du du du du du du du du
 * Medium (22.03%)
 * Total Accepted:    374.3K
 * Total Submissions: 1.7M
 * Testcase Example:  '[-1,0,1,2,-1,-4]'
 *
 * Given an array nums of n integers, are there elements a, b, c in nums such
 * that a + b + c = 0? Find all unique triplets in the array which gives the
 * sum of zero.
 *
 * Note:
 *
 * The solution set must not contain duplicate triplets.
 *
 * Example:
 *
 *
 * Given array nums = [-1, 0, 1, 2, -1, -4],
 *
 * A solution set is:
 * [
 * ⁠ [-1, 0, 1],
 * ⁠ [-1, -1, 2]
 * ]
 *
 *
 */

#include <iostream>
#include <set>
#include <vector>
using namespace std;
class Solution {
public:
  void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
  }
  int partition(vector<int> &nums, int low, int high) {
    int pivot = nums[high];
    int i = (low - 1);
    for (int j = low; j <= high - 1; j++) {
      if (nums[j] <= pivot) {
        i++;
        swap(&nums[i], &nums[j]);
      }
    }
    swap(&nums[i + 1], &nums[high]);
    return (i + 1);
  }

  void quickSort(vector<int> &nums, int low, int high) {
    if (low < high) {
      int pi = partition(nums, low, high);
      quickSort(nums, low, pi - 1);
      quickSort(nums, pi + 1, high);
    }
  }
  vector<vector<int>> threeSum(vector<int> &nums) {
    set<vector<int>> a;
    quickSort(nums, 0, nums.size() - 1);
    if (!nums.empty() && nums.back() < 0)
      return {};
    for (int i = 0; i < nums.size(); i++) {
      if (nums[i] > 0)
        break;
      int target = 0 - nums[i];
      int j = i + 1, l = nums.size() - 1;
      while (j < l) {
        if (nums[j] + nums[l] == target) {
          a.insert({nums[i], nums[j], nums[l]});
          while (j < l && nums[l] == nums[j + 1])
            ++j;
          while (j < l && nums[l] == nums[j - 1])
            --l;
          ++j;
          --l;
        } else if (nums[j] + nums[l] < target)
          ++j;
        else
          --l;
      }
    }
    return vector<vector<int>>(a.begin(), a.end());
  }
};
