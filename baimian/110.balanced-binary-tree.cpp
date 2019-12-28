/*
 * @lc app=leetcode id=110 lang=cpp
 *
 * [110] Balanced Binary Tree
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
#include <iostream>
using namespace std;
class Solution
{
public:
    bool isBalanced(TreeNode *root)
    {
        int height = 0;
        return checkBalanced(root, height);
    }
    bool checkBalanced(TreeNode *root, int &height)
    {
        if (root == NULL)
        {
            height = 0;
            return true;
        }
        int leftHeight = 0;
        int rightHeight = 0;
        if (!checkBalanced(root->left, leftHeight))
            return false;
        if (!checkBalanced(root->right, rightHeight))
            return false;
        if (abs(leftHeight - rightHeight) > 1)
            return false;
        height = max(leftHeight, rightHeight) + 1;
        return true;
    }
};
