class Solution
{
public:
    int openLock(vector<string> &deadends, string target)
    {
        if (target.compare("0000") == 0)
        {
            return 0;
        }

        unordered_map<string, int> vis;

        for (auto x : deadends)
        {
            vis[x] = 1;
        }

        queue<string> q;

        q.push(target);

        int ans = 0;

        while (!q.empty())
        {
            ans += 1;

            for (int i = 0; i < 4; i++)
            {
                string temp = q.front();
                temp[i] = char('0' + (temp[i] - '0' + 9) % 10);

                if (vis.find(temp) == vis.end())
                {
                    q.push(temp);
                    vis[temp] = 1;
                }
            }

            q.pop();
        }

        return ans == 0 ? -1 : ans;
    }
};