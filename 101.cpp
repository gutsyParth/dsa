/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    bool helper(TreeNode *p1, TreeNode *p2)
    {
        if (p1 == nullptr && p2 == nullptr)
        {
            return true;
        }
        else if (p1 == nullptr)
        {
            return false;
        }
        else if (p2 == nullptr)
        {
            return false;
        }

        return p1->val == p2->val && helper(p1->left, p2->right) && helper(p1->right, p2->left);
    }

    bool isSymmetric(TreeNode *root)
    {
        if (root == nullptr)
        {
            return true;
        }

        return helper(root->left, root->right);
    }
};