class Solution
{
public:
    bool fun(vector<vector<char>> &board, unordered_map<pair<int, int>, int> &vis, int i, int j)
    {
        if (i == 0 || j == 0 || i == board.size() - 1 || j == board[0].size() - 1)
        {
            return false;
        }

        vis[make_pair(i, j)] = 1;

        bool ans = true;

        if (vis[make_pair(i + 1, j)] == 0 && board[i + 1][j] == "O")
        {
            ans = fun(board, vis, i + 1, j);
        }

        if (vis[make_pair(i, j + 1)] == 0 && board[i][j + 1] == "O")
        {
            ans = fun(board, vis, i, j + 1);
        }

        if (vis[make_pair(i - 1, j)] == 0 && board[i - 1][j] == "O")
        {
            ans = fun(board, vis, i - 1, j);
        }

        if (vis[make_pair(i, j - 1)] == 0 && board[i][j - 1] == "O")
        {
            ans = fun(board, vis, i, j - 1);
        }

        return ans;
    }

    void fun1(int i, int j, vector<vector<char>> &board, unordered_map<pair<int, int>, int> &vis)
    {
        if (i == 0 || j == 0 || i == board.size() - 1 || j == board[0].size())
        {
            return;
        }

        board[i][j] = "X";

        if (vis[make_pair(i + 1, j)] != vis.end() && board[i + 1][j] == "O")
        {
            fun(board, vis, i + 1, j);
        }

        if (vis[make_pair(i, j + 1)] != vis.end() && board[i][j + 1] == "O")
        {
            fun(board, vis, i, j + 1);
        }

        if (vis[make_pair(i - 1, j)] != vis.end() && board[i - 1][j] == "O")
        {
            fun(board, vis, i - 1, j);
        }

        if (vis[make_pair(i, j - 1)] != vis.end() && board[i][j - 1] == "O")
        {
            fun(board, vis, i, j - 1);
        }
    }

    void solve(vector<vector<char>> &board)
    {
        int n = board.size();
        int m = board[0].size();

        vector<vector<int>> paint;
        unordered_map<pair<int, int>, int> vis;

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (board[i][j] == "X")
                {
                    if (!vis[make_pair(i, j)] && fun(board, vis, i, j))
                        paint.push_back({i, j});
                }
            }
        }

        vis.clear();
        for (auto x : paint)
        {
            fun1(x.first, x.second);
        }
    }
};