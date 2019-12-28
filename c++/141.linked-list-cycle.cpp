/*
 * @lc app=leetcode id=141 lang=cpp
 *
 * [141] Linked List Cycle
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

using namespace std;
#include <iostream>
// struct ListNode
// {
//     int val;
//     ListNode *next;
//     ListNode(int x) : val(x), next(NULL) {}
// };

class Solution1
{

    ListNode *reverse(ListNode *head)
    {
        ListNode *pre = NULL;
        ListNode *follow = NULL;
        while (head)
        {
            follow = head->next;
            head->next = pre;
            pre = head;
            head = follow;
        }
        return pre;
    }

public:
    bool hasCycle(ListNode *head)
    {
        ListNode *rev = reverse(head);
        if (head && head->next && rev == head)
            return true;
        else
            return false;
    }
};
class Solution
{

public:
    bool hasCycle(ListNode *head)
    {
        ListNode *fast = head;
        ListNode *slow = head;
        while (fast && slow && fast->next)
        {
            fast = fast->next->next;
            slow = slow->next;
            if (fast == slow)
                return true;
        }
        return false;
    }
};
