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
    vector<int> boundaryOfBinaryTree(TreeNode *root)
    {
        if (root == nullptr)
        {
            return {};
        }

        vector<vector<int>> ans{{root->val}};

        queue<TreeNode *> q;

        q.push(root);
        q.push(nullptr);

        vector<int> v;
        while (q.size() > 1)
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

            if (nd->left != nullptr)
            {
                v.push_back(nd->left->val);
                q.push(nd->left);
            }
            if (nd->right != nullptr)
            {
                v.push_back(nd->right->val);
                q.push(nd->right);
            }
        }

        vector<int> ans1 = {root->val};

        for (int i = 1; i < ans.size(); i++)
        {
            if (i == ans.size() - 1)
            {
                for (auto x : ans[i])
                {
                    ans1.push_back(x);
                }
            }
            else
            {
                if (ans[i].size() > 1)
                    ans1.push_back(ans[i][0]);
            }
        }

        for (int i = ans.size() - 2; i >= 1; i--)
        {
            ans1.push_back(ans[i].back());
        }

        return ans1;
    }
};