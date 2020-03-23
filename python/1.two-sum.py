#
# @lc app=leetcode id=1 lang=python3
#
# [1] Two Sum
#
# https://leetcode.com/problems/two-sum/description/
#
# algorithms
# Easy (44.34%)
# Likes:    11298
# Dislikes: 389
# Total Accepted:    2M
# Total Submissions: 4.4M
# Testcase Example:  '[2,7,11,15]\n9'
#
# Given an array of integers, return indices of the two numbers such that they
# add up to a specific target.
#
# You may assume that each input would have exactly one solution, and you may
# not use the same element twice.
#
# Example:
#
#
# Given nums = [2, 7, 11, 15], target = 9,
#
# Because nums[0] + nums[1] = 2 + 7 = 9,
# return [0, 1].
#
#
#
#将target-当前，的值放到map里面，后面直接使用map应对上。


# @lc code=start
class Solution:
    def twoSum(self, nums, target: int):
        mapp = {}
        length = len(nums)
        for i in range(length):
            if nums[i] not in mapp:
                mapp[target - nums[i]] = i
            else:
                return [mapp[nums[i]], i]
        return [-1, -1]


# @lc code=end