class Solution
{
public:
    void fun(vector<vector<int>> &graph, int i, vector<int> &vis)
    {
        if (vis[i] == 1)
        {
            return;
        }

        vis[i] = 1;

        for (auto x : graph[i])
        {
            fun(graph, x, vis);
        }
    }

    bool validTree(int n, vector<vector<int>> &edges)
    {
        int n = edges.size();

        vector<vector<int>> graph(n);

        for (auto x : edges)
        {
            graph[x[0]].push_back(x[1]);
            graph[x[1]].push_back(x[0]);
        }

        vector<int> vis(n);
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            if (vis[i] == 0)
            {
                if (cnt)
                {
                    return false;
                }
                fun(graph, i, vis);
                cnt = 1;
            }
        }

        return true;
    }
};