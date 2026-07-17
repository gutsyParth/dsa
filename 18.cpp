class Solution
{
public:
    int characterReplacement(string s, int k)
    {
        int n = s.size();
        int ans = 0;
        for (char i = 'A'; i <= 'Z'; i++)
        {
            int st = 0, en = 0;
            int cnt = k;
            while (en < n)
            {
                if (s[en] != i)
                {
                    cnt -= 1;
                }

                if (cnt < 0)
                {
                    while (s[st] == i && st <= en)
                    {
                        st += 1;
                    }

                    st += 1;
                    cnt += 1;
                }

                ans = max(ans, en - st + 1);
                en += 1;
            }
        }

        return ans;
    }
};