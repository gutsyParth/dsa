class Solution
{
public:
    void dfs(int i, int j, vector<vector<int>> &rooms, int dis)
    {
        if (i == rooms.size() || j == rooms[0].size() || i < 0 || j < 0 || rooms[i][j] == -1)
        {
            return;
        }

        rooms[i][j] = min(rooms[i][j], dis);

        dfs(i + 1, j, rooms, dis + 1);
        dfs(i, j + 1, rooms, dis + 1);
        dfs(i - 1, j, rooms, dis + 1);
        dfs(i, j - 1, rooms, dis + 1);
    }

    void wallsAndGates(vector<vector<int>> &rooms)
    {
        int m = rooms.size();
        int n = rooms[0].size();

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (rooms[i][j] == 0)
                {
                    dfs(i, j, rooms, dis);
                }
            }
        }
    }
};