/*
 * @lc app=leetcode id=101 lang=cpp
 *
 * [101] Symmetric Tree
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

// #define NULL nullptr
// struct TreeNode
// {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
// };

using namespace std;
class Solution
{
public:
    bool checkSymmetric(TreeNode *p, TreeNode *q)
    {
        if ((p == NULL) && (q == NULL))
            return true;
        if ((p == NULL) || (q == NULL))
            return false;
        if (p->val != q->val)
        {
            return false;
        }
        else
        {
            return checkSymmetric(p->left, q->right) && checkSymmetric(p->right, q->left);
        }
    }
    bool isSymmetric(TreeNode *root)
    {
        if (root == NULL)
            return true;
        if ((root->left == NULL) && (root->right == NULL))
            return true;
        if ((root->left == NULL) || (root->right == NULL))
            return false;
        return checkSymmetric(root->left, root->right);
    }
};
