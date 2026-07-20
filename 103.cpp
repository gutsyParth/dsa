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
        if (root == nullptr)
        {
            return {};
        }

        vector<vector<int>> ans{{root->val}};

        queue<TreeNode *> q;

        q.push(root);
        q.push(nullptr);

        vector<int> v;
        int flag = 0;
        while (q.size() > 1)
        {
            TreeNode *nd = q.front();
            q.pop();

            if (nd == nullptr)
            {
                flag = 1 - flag;
                ans.push_back(v);
                v.clear();
                q.push(nullptr);
                continue;
            }

            if (flag == 0)
            {
                if (nd->right != nullptr)
                {
                    v.push_back(nd->right->val);
                    q.push(nd->right);
                }
                if (nd->left != nullptr)
                {
                    v.push_back(nd->left->val);
                    q.push(nd->left);
                }
            }
            else
            {
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
        }

        return ans;
    }
};