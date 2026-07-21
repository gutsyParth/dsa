class Solution
{
public:
    vector<vector<int>> ans;

    void fun(int idx, int n, int k, vecotr<int> v)
    {
        if (idx == n && k == 0)
        {
            ans.push_back(v);
            return;
        }

        fun(idx + 1, n, k, v);
        vector<int> u = v;
        u.push_back(idx + 1);
        u.push_back(idx + 1, n, k - 1, v);
    }

    vector<vector<int>> combine(int n, int k)
    {
        fun(0, n, k, vector<int>());

        return ans;
    }
};