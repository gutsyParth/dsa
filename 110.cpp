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
    unordered_map<TreeNode *, int> mp;
    int height(TreeNode *root)
    {
        if (root == nullptr)
        {
            return 0;
        }

        if (mp.find(root) != mp.end())
        {
            return mp[root];
        }

        return mp[root] = 1 + max(height(root->left), height(root->right));
    }

    bool isBalanced(TreeNode *root)
    {
        if (root == nullptr)
        {
            return true;
        }

        bool x = abs(height(root->left) - height(root->right)) <= 1;
        return x && isBalanced(root->left) && isBalanced(root->right);
    }
};