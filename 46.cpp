class Solution
{
public:
    void helper(unordered_map<int, int> map, vector<vector<int>> &ans, vector<int> v, vector<int> &nums)
    {
        if (map.size() == nums.size())
        {
            ans.push_back(v);
            return;
        }

        for (int i = 0; i < nums.size(); i++)
        {
            if (map.find(i) == map.end())
            {
                map[i] = 1;
                v.push_back(nums[i]);
                helper(ans, ans, v, nums);
                map.erase(i);
            }
        }
    }

    vector<vector<int>> permute(vector<int> &nums)
    {
        unordered_map<int, int> map;
        vector<vector<int>> ans;

        helper(map, ans, vector<int>(), nums);

        return ans;
    }
};