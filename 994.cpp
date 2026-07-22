class Solution
{
public:
    int orangesRotting(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> moves = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

        queue<vector<int>> q;

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 2)
                {
                    q.push({i, j});
                }
            }
        }

        vector<vector<int>> vis(m, vector<int>(n));

        while (!q.empty())
        {
            vector<int> v = q.front();
            vis[v[0]][v[1]] = 1;
            q.pop();

            for (auto x : moves)
            {
                int i1 = x[0] + v[0];
                int j1 = x[1] + v[1];

                if (i1 >= 0 && j1 >= 0 && i1 < m && j1 < n &&
                    grid[i1][j1] == 1 && vis[i1][j1] == 0)
                {
                    q.push({i1, j1});
                    grid[i1][j1] = grid[v[0]][v[1]] + 1;
                    vis[i1][j1] = grid[v[0]][v[1]] + 1;
                }
            }
        }

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (vis[i][j] == 0 && grid[i][j] == 1)
                {
                    return -1;
                }
            }
        }
    }
};
