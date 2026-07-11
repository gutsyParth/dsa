class Solution
{
public:
    vector<vector<int>> insert(vector<vector<int>> &intervals, vector<int> &newInterval)
    {
        vector<vector<int>> ans;
        int i = 0;
        while (i < intervals.size())
        {
            if (intervals[i][1] < newInterval[0])
            {
                ans.push_back(intervals[i]);
                i += 1;
            }
            else
            {
                break;
            }
        }

        if (i == intervals.size())
        {
            ans.push_back(newInterval);
            return ans;
        }

        int j = i;

        while (i < intervals.size() && intervals[i][0] <= newInterval[1])
        {
            i += 1;
        }

        if (j == i)
        {
            ans.push_back(newInterval);

            while (i < intervals.size())
            {
                ans.push_back(newIntervals[i]);
                i += 1;
            }

            return ans;
        }

        ans.push_back({min(intervals[j][0], newInterval[0]), max(intervals[i - 1][1], newInterval[1])});

        while (i < intervals.size())
        {
            ans.push_back(intervals[i]);
            i += 1;
        }

        return ans;
    }
};