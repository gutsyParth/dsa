class Solution
{
public:
    int numDecodings(string s)
    {
        int n = s.size();

        vector<int> dp(n + 1);

        dp[0] = 1;
        dp[1] = 1;
        int x = (s[0] - '0') + (s[0 - 1] - '0') * 10;

        if (x >= 1 && x <= 26)
        {
            dp[1] += 1;
        }

        for (int i = 1; i <= n; i++)
        {
            x = (s[i] - '0') + (s[i - 1] - '0') * 10;

            if (x >= 1 && x <= 26)
            {
                dp[i] = max({dp[i], dp[i - 1], dp[i - 2]});
            }
            else
            {
                dp[i] = max(dp[i], dp[i - 1]);
            }
        }

        return dp[n - 1];
    }
};