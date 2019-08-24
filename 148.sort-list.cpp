/*
 * @lc app=leetcode id=148 lang=cpp
 *
 * [148] Sort List
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
public:
    ListNode *sortList_quick(ListNode *head)
    {
    }

    ListNode *sortList_insert(ListNode *head)
    {
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode *pre = dummy, *cur = head;
        while (cur)
        {
            if ((cur->next) && (cur->next->val < cur->val))
            {
                while ((pre->next) && (pre->next->val < cur->next->val))
                {
                    pre = pre->next;
                }
                ListNode *temp = pre->next;
                pre->next = cur->next;
                cur->next = cur->next->next;
                pre->next->next = temp;
                pre = dummy;
            }
            else
            {
                cur = cur->next;
            }
        }
        return dummy->next;
    }
};
