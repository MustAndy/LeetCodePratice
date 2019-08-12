/*
 * @lc app=leetcode id=234 lang=cpp
 *
 * [234] Palindrome Linked List
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
    bool isPalindrome(ListNode *head)
    {
        if (!head || !head->next)
            return true;
        ListNode *slow = head, *fast = head;
        while (fast->next && fast->next->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode *last = slow->next, *pre = head;
        while (last->next)
        {
            ListNode *tmp = last->next;
            last->next = tmp->next;
            tmp->next = slow->next;
            slow->next = tmp;
        }
        while (slow->next)
        {
            slow = slow->next;
            if (pre->val != slow->val)
                return false;
            pre = pre->next;
        }
        return true;
    }
};
class Solution1
{
public:
    bool isPalindrome(ListNode *head)
    {
        ListNode *cur = head;
        stack<int> st;
        while (cur)
        {
            st.push(cur->val);
            cur = cur->next;
        }
        while (head)
        {
            int t = st.top();
            st.pop();
            if (head->val != t)
                return false;
            head = head->next;
        }
        return true;
    }
};