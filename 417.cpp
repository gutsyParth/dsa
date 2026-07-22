class Solution
{
public:
    void dfs(vector<vector<int>> &heights, int i, int j,
             vector<vector<int>> &vis)
    {

        vis[i][j] = 1;

        int dirs[4][2] = {
            {1, 0},
            {-1, 0},
            {0, 1},
            {0, -1}};

        for (auto &d : dirs)
        {
            int ni = i + d[0];
            int nj = j + d[1];

            if (ni >= 0 && nj >= 0 &&
                ni < heights.size() &&
                nj < heights[0].size() &&
                !vis[ni][nj] &&
                heights[ni][nj] >= heights[i][j])
            {

                dfs(heights, ni, nj, vis);
            }
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>> &heights)
    {

        int m = heights.size();
        int n = heights[0].size();

        vector<vector<int>> pacific(m, vector<int>(n, 0));
        vector<vector<int>> atlantic(m, vector<int>(n, 0));

        // Pacific: top row
        for (int j = 0; j < n; j++)
            if (!pacific[0][j])
                dfs(heights, 0, j, pacific);

        // Pacific: left column
        for (int i = 0; i < m; i++)
            if (!pacific[i][0])
                dfs(heights, i, 0, pacific);

        // Atlantic: bottom row
        for (int j = 0; j < n; j++)
            if (!atlantic[m - 1][j])
                dfs(heights, m - 1, j, atlantic);

        // Atlantic: right column
        for (int i = 0; i < m; i++)
            if (!atlantic[i][n - 1])
                dfs(heights, i, n - 1, atlantic);

        vector<vector<int>> ans;

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (pacific[i][j] && atlantic[i][j])
                    ans.push_back({i, j});
            }
        }

        return ans;
    }
};