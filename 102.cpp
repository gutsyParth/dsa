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
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        vector<vector<int>> ans;

        queue<TreeNode *> q;

        q.push(root);
        q.push(nullptr);

        vector<int> v;
        while (!q.front(nullptr))
        {
            TreeNode *nd = q.front();
            q.pop();

            if (nd == nullptr)
            {
                ans.push_back(v);
                v.clear();
                q.push(nullptr);
                continue;
            }

            if (nd.left == nullptr)
            {
                v.push_back(nd->left->val);
                q.push(nd.left);
            }
            if (nd->right == nullptr)
            {
                v.push_back(nd->right->val);
                q.push(nd->right);
            }
        }

        return ans;
    }
};