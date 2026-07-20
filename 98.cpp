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
    unordered_map<TreeNode *, int> map_max_left;

    int max_left(TreeNode *root)
    {
        if (root == nullptr)
        {
            return INT_MIN;
        }

        if (map_max_left.find(root) != map_max_left.end())
        {
            return map_max_left[root];
        }

        return map_max_left[root] = max({root->val, max_left(root->left), max_left(root->right)});
    }

    unordered_map<TreeNode *, int> map_min_right;

    int min_right(TreeNode *root)
    {
        if (root == nullptr)
        {
            return INT_MAX;
        }

        if (map_min_right.find(root) != map_min_right.end())
        {
            return map_min_right[root];
        }

        return map_min_right[root] = min({root->val, min_right(root->left), min_right(root->right)});
    }

    bool isValidBST(TreeNode *root)
    {
        if (root == nullptr)
        {
            return true;
        }

        int num1 = max_left(root->left);
        int num2 = min_right(root->right);

        if (root->val > num1 && root->val < num2)
        {
            return true && isValidBST(root->left) && isValidBST(root->right);
        }

        return false;
    }
};