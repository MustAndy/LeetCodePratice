#
# @lc app=leetcode id=2 lang=python3
#
# [2] Add Two Numbers
#
# https://leetcode.com/problems/add-two-numbers/description/
#
# algorithms
# Medium (31.61%)
# Likes:    7337
# Dislikes: 1896
# Total Accepted:    1.3M
# Total Submissions: 3.8M
# Testcase Example:  '[2,4,3]\n[5,6,4]'
#
# You are given two non-empty linked lists representing two non-negative
# integers. The digits are stored in reverse order and each of their nodes
# contain a single digit. Add the two numbers and return it as a linked list.
#
# You may assume the two numbers do not contain any leading zero, except the
# number 0 itself.
#
# Example:
#
#
# Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
# Output: 7 -> 0 -> 8
# Explanation: 342 + 465 = 807.
#
#
#


# @lc code=start
# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None


class Solution:
    def addTwoNumbers(self, l1, l2):
        carry = 0
        root = n = ListNode(0)
        while l1 or l2 or carry:
            v1 = v2 = 0
            if l1:
                v1 = l1.val
                l1 = l1.next
            if l2:
                v2 = l2.val
                l2 = l2.next
            carry, val = divmod(v1 + v2 + carry, 10)
            n.next = ListNode(val)
            n = n.next
        return root.next


class Solution1:
    def addTwoNumbers(self, l1, l2):
        result = list()
        #resultNode = ListNode()
        dig = 0
        while l1 or l2:
            if l1 and l2:
                if l1.val + l2.val + dig >= 10:

                    result.append(l1.val + l2.val + dig - 10)
                    dig = 1
                    l2 = l2.next
                    l1 = l1.next
                else:
                    result.append(l1.val + l2.val + dig)
                    dig = 0
                    l2 = l2.next
                    l1 = l1.next
            elif l1:
                if l1.val + dig >= 10:
                    result.append(l1.val + dig - 10)
                    dig = 1
                else:
                    result.append(l1.val + dig)
                    dig = 0
                l1 = l1.next
            elif l2:
                if l2.val + dig >= 10:
                    result.append(l2.val + dig - 10)
                    dig = 1
                else:
                    result.append(l2.val + dig)
                    dig = 0
                l2 = l2.next
        if dig == 1:
            result.append(1)
        head = ListNode(result[0])
        resultt = head
        for i in range(1, len(result)):
            head.next = ListNode(result[i])
            head = head.next
        return resultt

        print(result)


# @lc code=end
