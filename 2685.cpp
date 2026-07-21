class Solution
{
public:
    int countCompleteComponents(int n, vector<vector<int>> &edges)
    {
        vector<vector<int>> graph(n);

        for (auto x : edges)
        {
            graph[x[0]].push_back(x[1]);
            graph[x[1]].push_back(x[0]);
        }

        vector<int> checked(n);
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            vector<int> vis(n, 0);

            for (auto x : graph[i])
            {
                vis[x] = 1;
                checked[x] = 1;
            }

            bool flag = true;
            for (auto x : graph[i])
            {
                if (graph[x].size() == graph[i].size())
                {
                    for (auto y : graph[graph[i]])
                    {
                        if (vis[y] == 0)
                        {
                            flag = false;
                            break;
                        }
                    }
                    if (flag == false)
                    {
                        break;
                    }
                }
            }
            if (flag)
            {
                ans += 1;
            }
        }

        return ans;
    }
};