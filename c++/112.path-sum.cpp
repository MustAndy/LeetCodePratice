/*
 * @lc app=leetcode id=112 lang=cpp
 *
 * [112] Path Sum
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

// struct TreeNode
// {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
// };
class Solution1
{
public:
    bool hasPathSum(TreeNode *root, int sum)
    {
        if (root == NULL)
        {
            return false;
        }
        int newsum = sum - root->val;
        if (root->left == NULL && root->right == NULL)
        {
            return newsum == 0;
        }
        return hasPathSum(root->left, newsum) || hasPathSum(root->right, newsum);
    }
};
class Solution
{
public:
    bool hasPathSum(TreeNode *root, int sum)
    {
        if (root == NULL && sum == 0)
            return false;
        if (root == NULL && sum != 0)
            return false;
        if (root->val == sum && root->left == NULL && root->right == NULL)
            return true;
        if (hasPathSum(root->left, (sum - root->val)))
            return true;
        if (hasPathSum(root->right, (sum - root->val)))
            return true;

        return false;
    }
};
