/*
 * @lc app=leetcode id=144 lang=cpp
 *
 * [144] Binary Tree Preorder Traversal
 *
 * https://leetcode.com/problems/binary-tree-preorder-traversal/description/
 *
 * algorithms
 * Medium (52.28%)
 * Likes:    908
 * Dislikes: 45
 * Total Accepted:    373.5K
 * Total Submissions: 711.6K
 * Testcase Example:  '[1,null,2,3]'
 *
 * Given a binary tree, return the preorder traversal of its nodes' values.
 * 
 * Example:
 * 
 * 
 * Input: [1,null,2,3]
 * ⁠  1
 * ⁠   \
 * ⁠    2
 * ⁠   /
 * ⁠  3
 * 
 * Output: [1,2,3]
 * 
 * 
 * Follow up: Recursive solution is trivial, could you do it iteratively?
 * 
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
#include <vector>
using namespace std;
class Solution
{
public:
    vector<int> preorderTraversal(TreeNode *root)
    {
        vector<int> v;
        if (!root)
            return v;
        TreeNode *temp = root;
        stack<TreeNode *> s;
        s.push(root);
        while (!s.empty())
        {
            temp = s.top();
            s.pop();
            v.push_back(temp->val);
            if (temp->right)
                s.push(temp->right);
            if (temp->left)
                s.push(temp->left);
        }
        return v;
    }

    vector<int> preorderTraversal1(TreeNode *root)
    {
        vector<int> result;
        if (root == NULL)
            return result;
        result.push_back(root->val);
        vector<int> leftresult = preorderTraversal(root->left);
        vector<int> rightresult = preorderTraversal(root->right);
        result.insert(result.end(), leftresult.begin(), leftresult.end());
        result.insert(result.end(), rightresult.begin(), rightresult.end());
        return result;
    }
};
