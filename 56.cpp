class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> ans;

        int i = intervals[0][0];
        int j = intervals[0][1];

        for (int k = 1; k < intervals.size(); k++)
        {
            if (intervals[k][0] <= j)
            {
                j = intervals[k][1];
            }
            else
            {
                ans.push_back({i, j});
                i = intervals[k][0];
                j = intervals[k][1];
            }
        }
        ans.push_back({i, j});

        return ans;
    }
};