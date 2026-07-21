class Solution
{
public:
    int fun(vector<vector<char>> &grid, int i, int j)
    {
        if (i < 0 || j < 0)
        {
            return 0;
        }
        else if (i == grid.size() || j == grid[0].size())
        {
            return 0;
        }
        else if (grid[i][j] == '0')
        {
            return 0;
        }
        else if (grid[i][j] == '1')
        {
            grid[i][j] = '0';
        }

        return 1 + fun(grid, i + 1, j) + fun(grid, i, j + 1) + fun(grid, i - 1, j) + fun(grid, i, j - 1);
    }

    int maxAreaOfIsland(vector<vector<char>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();

        int ans = 0;
        for (int i = 0; i < m; i++)
        {

            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == '1')
                {
                    ans = max(ans, fun(grid, i, j));
                }
            }
        }

        return ans;
    }
};