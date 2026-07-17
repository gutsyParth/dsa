class Solution
{
public:
    vector<int> findClosestElements(vector<int> &arr, int k, int x)
    {
        vector<pair<int, int>> v;

        for (auto y : arr)
        {
            v.push_back(make_pair(abs(x - y), y));
        }

        sort(v.begin(), v.end());

        vector<int> ans;

        for (int i = 0; i < k; i++)
        {
            ans.push_back(v[i].second);
        }

        return ans;
    }
};