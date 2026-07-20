/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution
{
public:
    void inorder(TreeNode *root, vector<long long> &lvl_sum, int cur_lvl)
    {
        if (root == nullptr)
        {
            return;
        }

        if (lvl_sum.size() <= cur_lvl)
        {
            lvl_sum.push_back((long long)root->val);
        }
        else
        {
            lvl_sum[cur_lvl] += (long long)root->val;
        }
        inorder(root->left, lvl_sum, cur_lvl + 1);
        inorder(root->right, lvl_sum, cur_lvl + 1);
    }

    long long kthLargestLevelSum(TreeNode *root, int k)
    {
        vector<long long> lvl_sum;

        inorder(root, lvl_sum, 0);

        if (lvl_sum.size() < k)
        {
            return -1;
        }

        sort(lvl_sum.begin(), lvl_sum.end(), greater<long long>());

        return lvl_sum[k - 1];
    }
};