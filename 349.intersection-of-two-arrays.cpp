/*
 * @lc app=leetcode id=349 lang=cpp
 *
 * [349] Intersection of Two Arrays
 */
#include <map>
#include <vector>
using namespace std;
class Solution
{
public:
    vector<int> intersection(vector<int> &nums1, vector<int> &nums2)
    {
        vector<int> result;
        map<int, int> n1;
        int length1 = nums1.size(), length2 = nums2.size();
        for (int i = 0; i < length1; ++i)
        {
            for (int j = 0; j < length2; ++j)
            {
                if (nums1[i] == nums2[j])
                {
                    if (n1.find(nums1[i]) != n1.end())
                    {
                        n1[nums1[i]] += 1;
                    }
                    else
                    {
                        n1[nums1[i]] = 1;
                    }
                }
            }
        }
        map<int, int>::iterator it;
        for (it = n1.begin(); it != n1.end(); ++it)
        {
            result.push_back(it->first);

            n1.erase(it);
        }

        return result;
    }
    vector<int> intersection1(vector<int> &nums1, vector<int> &nums2)
    {
        map<int, int> n1, n2;
        int length1 = nums1.size(), length2 = nums2.size();
        for (int i = 0; i < length1; ++i)
        {
            if (n1.find(nums1[i]) != n1.end())
            {
                nums1[i] += 1;
            }
            else
            {
                nums1[i] = 1;
            }
        }
        for (int i = 0; i < length2; ++i)
        {
            if (n2.find(nums1[i]) != n2.end())
            {
                nums2[i] += 1;
            }
            else
            {
                nums2[i] = 1;
            }
        }
        for (int i = 0; i < length1; ++i)
        {
        }
        vector<int> result;
        return result;
    }
};
