class Solution
{
public:
    void wallsAndGates(vector<vector<int>> &rooms)
    {
        int m = rooms.size();
        int n = rooms[0].size();

        vector<vector<int>> moves = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

        queue<vector<int>> q;

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (rooms[i][j] == 0)
                {
                    q.push({i, j});
                }
            }
        }

        vector<vector<int>> vis1(m, vector<int>(n));

        while (!q.empty())
        {
            vector<int> v = q.front();
            vis1[v[0]][v[1]] = 1;
            q.pop();

            for (auto x : moves)
            {
                int i1 = x[0] + v[0];
                int j1 = x[1] + v[1];

                if (i1 >= 0 && j1 >= 0 && i1 < m && j1 < n && vis1[i1][j1] == 0)
                {
                    q.push({i1, j1});
                    rooms[i1][j1] = rooms[v[0]][v[1]] + 1;
                }
            }
        }
    }
}

    [2147483647, -1, 0, 2147483647]
    [2147483647, 2147483647, 2147483647, -1]
    [2147483647, -1, 2147483647, -1]
    [0, -1, 2147483647, 2147483647]
