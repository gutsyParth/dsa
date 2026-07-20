class Solution
{
public:
    void helper(unordered_map<int, int> &map, set<vector<int>> &ans,
                vector<int> v, vector<int> &nums)
    {
        if (map.size() == nums.size())
        {
            ans.push_back(v);
            return;
        }

        for (int i = 0; i < nums.size(); i++)
        {
            vector<int> u = v;
            if (map.find(i) == map.end())
            {
                map[i] = 1;
                u.push_back(nums[i]);
                helper(map, ans, u, nums);
                map.erase(i);
            }
        }
    }

    vector<vector<int>> permuteUnique(vector<int> &nums)
    {
        unordered_map<int, int> map;
        set<vector<int>> ans;

        helper(map, ans, vector<int>(), nums);

        return ans;
    }
};