class Solution
{
public:
    void helper(vector<int> &nums, vector<vector<int>> &ans, int i, vector<int> v)
    {
        if (i == nums.size())
        {
            ans.push_back(v);
            return;
        }

        helper(nums, ans, i + 1, v);
        vector<int> u = v;
        u.push_back(nums[i]);
        helper(nums, ans, i + 1, u);
    }

    vector<vector<int>> subsets(vector<int> &nums)
    {
        vector<vector<int>> ans;
        vector<int> v;
        helper(nums, ans, i, v);

        return ans;
    }
};