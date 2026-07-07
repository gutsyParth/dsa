class Solution
{
public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        unordered_map<int, int> mp;

        for (auto x : nums)
        {
            mp[x] += 1;
        }

        vector<pair<int, int>> v;

        for (const auto &[num, freq] : mp)
        {
            v.push_back(make_pair(freq, num));
        }

        sort(v.begin(), v.end());

        vector<int> ans;

        for (int i = 0; i < min(k, v.size()); i++)
        {
            ans.push_back(v[i].second);
        }

        return ans;
    }
};