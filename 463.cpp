class Solution
{
public:
    int fun(vector<vector<int>> &grid, int i, int j)
    {
        if (i < 0 || j < 0)
        {
            return 0;
        }
        else if (i == grid.size() || j == grid[0].size())
        {
            return 0;
        }
        else if (grid[i][j] == 0 || grid[i][j] == -1)
        {
            return 0;
        }

        grid[i][j] = -1;
        int cnt = 0;

        if (i - 1 < 0 || grid[i - 1][j] == 0)
        {
            cnt += 1;
        }

        if (j - 1 < 0 || grid[i][j - 1] == 0)
        {
            cnt += 1;
        }

        if (i + 1 < grid.size() || grid[i + 1][j] == 0)
        {
            cnt += 1;
        }

        if (j + 1 < grid[0].size() || grid[i][j + 1] == 0)
        {
            cnt += 1;
        }

        return cnt + fun(grid, i + 1, j) + fun(grid, i, j + 1) + fun(grid, i - 1, j) +
               fun(grid, i, j - 1);
    }

    int islandPerimeter(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();

        int ans = 0;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 1)
                {
                    ans = max(ans, fun(grid, i, j));
                    break;
                }
            }
        }

        return ans;
    }
};