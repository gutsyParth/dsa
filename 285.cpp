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
    TreeNode *inorderSuccessor(TreeNode *root, TreeNode *p)
    {
        if (root == nullptr)
        {
            return root;
        }

        TreeNode *lt = inorderSuccessor(root->left, p);
        TreeNode *rt = inorderSuccessor(root->right, p);

        if (lt != nullptr && pt != nullptr && lt->val > p->val && rt->val > p->val)
        {
            if (lt->val < p->val)
            {
                return lt;
            }
            return rt;
        }
        else if (lt != nullptr && lt->val > p->val)
        {
            return lt;
        }
        else if (rt != nullptr && rt->val > p->val)
        {
            return rt;
        }

        return nullptr;
    }
};