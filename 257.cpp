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
    void helper(TreeNode *root, string x, vector<string> &ans)
    {
        if (root->left == nullptr && root->right == nullptr)
        {
            ans.push_back(x + string(root->val));
            return;
        }

        helper(root, x + root->val, ans);
    }

    vector<string> binaryTreePaths(TreeNode *root)
    {
        if (root == nullptr)
        {
            return {};
        }
        vector<string> ans;
        helper(root, "", ans);
        return ans;
    }
};