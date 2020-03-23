#
# @lc app=leetcode id=3 lang=python3
#
# [3] Longest Substring Without Repeating Characters
#
# https://leetcode.com/problems/longest-substring-without-repeating-characters/description/
#
# algorithms
# Medium (28.74%)
# Likes:    8084
# Dislikes: 494
# Total Accepted:    1.4M
# Total Submissions: 4.7M
# Testcase Example:  '"abcabcbb"'
#
# Given a string, find the length of the longest substring without repeating
# characters.
#
#
# Example 1:
#
#
# Input: "abcabcbb"
# Output: 3
# Explanation: The answer is "abc", with the length of 3.
#
#
#
# Example 2:
#
#
# Input: "bbbbb"
# Output: 1
# Explanation: The answer is "b", with the length of 1.
#
#
#
# Example 3:
#
#
# Input: "pwwkew"
# Output: 3
# Explanation: The answer is "wke", with the length of 3.
# ⁠            Note that the answer must be a substring, "pwke" is a
# subsequence and not a substring.
#
#
#
#
#
# 抓好前后两个指针度量的位置，灵活使用hash表来统计现状


# @lc code=start
class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        result, i, j = 0, 0, 0
        resultDict = {}
        for c in s:
            j += 1
            resultDict[c] = resultDict.get(c, 0) + 1
            while resultDict[c] > 1:
                resultDict[s[i]] -= 1
                i += 1
            result = max(result, j - i)
        return result

        # @lc code=end
