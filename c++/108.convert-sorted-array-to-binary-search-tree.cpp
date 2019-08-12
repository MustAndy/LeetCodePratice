/*
 * @lc app=leetcode id=108 lang=cpp
 *
 * [108] Convert Sorted Array to Binary Search Tree
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution
{
public:
    TreeNode *sortedArrayToBST(vector<int> &nums)
    {
        return findArrayToBST(nums, 0, nums.size());
    }
    TreeNode *findArrayToBST(vector<int> &nums, int start, int end)
    {
        if (end <= start)
            return NULL;
        int mid = (start + end) / 2;
        TreeNode *root = new TreeNode(nums[mid]);
        root->left = findArrayToBST(nums, start, mid);
        root->right = findArrayToBST(nums, mid + 1, end);
        return root;
    }
};
