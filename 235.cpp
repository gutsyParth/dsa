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
    TreeNode *lca = nullptr;
    bool lca_fun(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        if (root == nullptr)
        {
            return false;
        }

        bool lt = lca_fun(root->left, p, q);
        bool rt = lca_fun(root->right, p, q);

        if ((root->val == p->val || root->val == q->val) && lca == nullptr)
        {
            if (lt || rt)
            {
                lca = root;
            }
            return true;
        }
        else if (lt && rt && lca == nullptr)
        {
            lca = root;
            return true;
        }

        return lt || rt;
    }

    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        lca_fun(root, p, q);

        return lca;
    }
};