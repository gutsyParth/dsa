class Solution
{
public:
    int eraseOverlapIntervals(vector<vector<int>> &intervals)
    {
        sort(intervals.begin(), intervals.end(), [](vector<int> a, vector<int> b)
             { a[1] < b[1]; });

        int ans = 0;
        int n = intervals.size();
        int k = INT_MIN;
        for (int i = 0; i < n; i++)
        {
            if (intervals[i][0] > k)
            {
                k = intervals[i][1];
            }
            else
            {
                ans += 1;
            }
        }

        return ans;
    }
};