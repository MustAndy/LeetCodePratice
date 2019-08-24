/*
 * @lc app=leetcode id=55 lang=cpp
 *
 * [55] Jump Game
 */
#include <vector>
using namespace std;
class Solution
{
public:
    bool canJump(vector<int> &nums)
    {
        int target = nums.size();
        if (target == 1)
            return true;
        int length = nums.size();
        int max_jump = 0;
        for (int i = 0; i <= max_jump; ++i)
        {
            if ((nums[i] + i) > max_jump)
            {
                if ((nums[i] + i) >= (target - 1))
                    return true;
                else
                {
                    max_jump = nums[i] + i;
                }
            }
        }
        return false;
    }
};
