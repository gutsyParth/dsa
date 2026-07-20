class Solution
{
public:
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
    {
        long long n = 1 << candidates.size();
        set<vector<int>> ans;
        for (long long i = 0; i < n; i++)
        {
            int sum = 0;
            for (long long j = 0; j < candidates.size(); j++)
            {
                if (i & 1 << j)
                    sum += candidates[j];
            }

            vector<int> v;
            if (sum == target)
            {
                for (int j = 0; j < candidates.size(); j++)
                {
                    if (i & 1 << j)
                        v.push_back(candidates[j]);
                }
                sort(v.begin(), v.end());
                ans.insert(v);
            }
        }

        return vector<vector<int>>(ans.begin(), ans.end());
    }
};