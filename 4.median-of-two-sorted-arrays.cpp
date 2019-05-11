/*
 * @lc app=leetcode id=4 lang=cpp
 *
 * [4] Median of Two Sorted Arrays
 *
 * https://leetcode.com/problems/median-of-two-sorted-arrays/description/
 *
 * algorithms
 * Hard (25.69%)
 * Total Accepted:    394.6K
 * Total Submissions: 1.5M
 * Testcase Example:  '[1,3]\n[2]'
 *
 * There are two sorted arrays nums1 and nums2 of size m and n respectively.
 *
 * Find the median of the two sorted arrays. The overall run time complexity
 * should be O(log (m+n)).
 *
 * You may assume nums1 and nums2 cannot be both empty.
 *
 * Example 1:
 *
 *
 * nums1 = [1, 3]
 * nums2 = [2]
 *
 * The median is 2.0
 *
 *
 * Example 2:
 *
 *
 * nums1 = [1, 2]
 * nums2 = [3, 4]
 *
 * The median is (2 + 3)/2 = 2.5
 *
 *
 */
#include <algorithm>
#include <iostream>
#include <limits.h>
#include <vector>
using namespace std;
class Solution
{
  public:
    double findMedianSortedArrays2(vector<int> &nums1, vector<int> &nums2)
    {
        double result = 0;
        vector<int> sum;
        for (int i = 0; i < nums1.size(); i++)
        {
            sum.push_back(nums1[i]);
        }
        for (int i = 0; i < nums2.size(); i++)
        {
            sum.push_back(nums2[i]);
        }
        sort(sum.begin(), sum.end());

        if (sum.size() % 2 == 0)
        {
            result += sum[(sum.size() / 2)];
            result += sum[(sum.size() / 2 - 1)];
            return result / 2;
        }
        else
        {
            return sum[(sum.size() / 2)];
        }
    }
    double findMedianSortedArrays1(vector<int> &nums1, vector<int> &nums2)
    {

        auto a_begin = nums1.begin();
        auto a_end = nums1.end();
        auto b_begin = nums2.begin();
        auto b_end = nums2.end();

        if (b_begin == b_end)
        {
            return returnmid(nums1);
        }
        if (a_begin == a_end)
        {
            return returnmid(nums2);
        }
        --a_end;
        --b_end;
        if ((*a_end) < (*b_begin))
        {
            vector<int> sum;
            for (int i = 0; i < nums1.size(); i++)
                sum.push_back(nums1[i]);
            for (int i = 0; i < nums2.size(); i++)
                sum.push_back(nums2[i]);
            return returnmid(sum);
        }
        else if ((*b_end) < (*a_begin))
        {
            vector<int> sum;
            for (int i = 0; i < nums2.size(); i++)
                sum.push_back(nums2[i]);
            for (int i = 0; i < nums1.size(); i++)
                sum.push_back(nums1[i]);
            return returnmid(sum);
        }
        else
        {
            vector<int> sum;
            for (int i = 0; i < nums1.size(); i++)
                sum.push_back(nums1[i]);
            for (int i = 0; i < nums2.size(); i++)
                sum.push_back(nums2[i]);
            sort(sum.begin(), sum.end());
            return returnmid(sum);
        }

        return 0.0;
    }
    double returnmid(vector<int> &nums)
    {
        int length = nums.size();
        if (length == 1)
            return nums[0];
        double mid = nums[length / 2];
        double mid2 = nums[length / 2 - 1];

        return (length % 2 == 0) ? ((mid + mid2) / 2) : mid;
    }

    double findMedianSortedArrays3(vector<int> &nums1, vector<int> &nums2)
    {
        int m = nums1.size(), n = nums2.size(), left = (m + n + 1) / 2,
            right = (m + n + 2) / 2;
        return (findKth(nums1, 0, nums2, 0, left) +
                findKth(nums1, 0, nums2, 0, right)) /
               2.0;
    }
    int findKth(vector<int> &nums1, int i, vector<int> &nums2, int j, int k)
    {
        if (i >= nums1.size())
            return nums2[j + k - 1];
        if (j >= nums2.size())
            return nums1[i + k - 1];
        if (k == 1)
            return min(nums1[i], nums2[j]);
        int midVal1 =
            (i + k / 2 - 1 < nums1.size()) ? nums1[i + k / 2 - 1] : INT_MAX;
        int midVal2 =
            (j + k / 2 - 1 < nums2.size()) ? nums2[j + k / 2 - 1] : INT_MAX;
        if (midVal1 < midVal2)
        {
            return findKth(nums1, i + k / 2, nums2, j, k - k / 2);
        }
        else
        {
            return findKth(nums1, i, nums2, j + k / 2, k - k / 2);
        }
    }
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        int N1 = nums1.size();
        int N2 = nums2.size();
        if (N1 < N2)
            return findMedianSortedArrays(nums2,
                                          nums1); // Make sure A2 is the shorter one.

        int lo = 0, hi = N2 * 2;
        while (lo <= hi)
        {
            int mid2 = (lo + hi) / 2;  // Try Cut 2
            int mid1 = N1 + N2 - mid2; // Calculate Cut 1 accordingly

            double L1 =
                (mid1 == 0)
                    ? INT_MIN
                    : nums1[(mid1 - 1) / 2]; // Get L1, R1, L2, R2 respectively
            double L2 = (mid2 == 0) ? INT_MIN : nums2[(mid2 - 1) / 2];
            double R1 = (mid1 == N1 * 2) ? INT_MAX : nums1[(mid1) / 2];
            double R2 = (mid2 == N2 * 2) ? INT_MAX : nums2[(mid2) / 2];

            if (L1 > R2)
                lo = mid2 +
                     1; // A1's lower half is too big; need to move C1 left (C2 right)
            else if (L2 > R1)
                hi = mid2 - 1; // A2's lower half too big; need to move C2 left.
            else
                return (max(L1, L2) + min(R1, R2)) /
                       2; // Otherwise, that's the right cut.
        }
        return -1;
    }
};
