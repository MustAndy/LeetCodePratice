/*
 * @lc app=leetcode id=111 lang=cpp
 *
 * [111] Minimum Depth of Binary Tree
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
    int minDepth(TreeNode *root)
    {
        return BFS(root, 1);
    }
    int BFS(TreeNode *root, int depth)
    {
        if (root == NULL)
            return 0;

        if ((root->left == NULL) && (root->right == NULL))
            return depth;

        if ((root->left == NULL))
            return BFS(root->right, depth + 1);

        if ((root->right == NULL))
            return BFS(root->left, depth + 1);

        if ((root->left != NULL) && (root->right != NULL))
        {
            int left = BFS(root->left, depth + 1);
            int right = BFS(root->right, depth + 1);

            return left < right ? left : right;
        }

        return 0;
    }
};