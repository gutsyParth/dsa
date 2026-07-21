class Solution
{
public:
    void fun(vector<vector<char>> &grid, int i, int j)
    {
        if (i < 0 || j < 0)
        {
            return;
        }
        else if (i == grid.size() || j == grid[0].size())
        {
            return;
        }
        else if (grid[i][j] == '0')
        {
            return;
        }
        else if (grid[i][j] == '1')
        {
            grid[i][j] == '0';
        }

        fun(grid, i + 1, j);
        fun(grid, i, j + 1);
        fun(grid, i - 1, j);
        fun(grid, i, j - 1);

        return;
    }

    int numIslands(vector<vector<char>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();

        for (int i = 0; i < m; i++)
        {
            int ans = 0;
            for (int j = 0; j < n; j++)
            {
                if (grids[i][j] == '1')
                {
                    fun(grids, i, j);
                    ans += 1;
                }
            }
        }
    }
};