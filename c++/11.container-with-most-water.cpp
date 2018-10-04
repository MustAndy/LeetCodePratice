/*
 * [11] Container With Most Water
 *
 * https://leetcode.com/problems/container-with-most-water/description/
 *
 * algorithms
 * Medium (38.69%)
 * Total Accepted:    240.3K
 * Total Submissions: 621.2K
 * Testcase Example:  '[1,8,6,2,5,4,8,3,7]'
 *
 * Given n non-negative integers a1, a2, ..., an , where each represents a
 * point at coordinate (i, ai). n vertical lines are drawn such that the two
 * endpoints of line i is at (i, ai) and (i, 0). Find two lines, which together
 * with x-axis forms a container, such that the container contains the most
 * water.
 *
 * Note: You may not slant the container and n is at least 2.
 *
 *
 *
 *
 *
 * The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7]. In
 * this case, the max area of water (blue section) the container can contain is
 * 49.
 *
 *
 *
 * Example:
 *
 *
 * Input: [1,8,6,2,5,4,8,3,7]
 * Output: 49
 *
 */
#include <iostream>
#include <limits.h>
#include <stdio.h>
#include <string>
#include <vector>
using namespace std;
class Solution
{
  public:
    int maxArea(vector<int> &height)
    {
        int i = 0, j = height.size() - 1, count = 0;
        while (i < j)
        {
            int waterHeight = height[i] > height[j] ? height[j] : height[i];
            int area = waterHeight * (j - i);
            count = area > count ? area : count;
            if (height[i] > height[j])
                --j;
            else
                ++i;
        }
        return count;
    }
};