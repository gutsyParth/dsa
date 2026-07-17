class Solution
{
public:
    bool checkInclusion(string s1, string s2)
    {
        int n = s1.size();
        int m = s2.size();

        if (n > m)
        {
            return false;
        }

        vector<int> v(26, 0);

        for (auto x : s1)
        {
            v[x - 'a']++;
        }

        vector<int> u(26, 0);
        for (int i = 0; i < n; i++)
        {
            u[s2[i] - 'a']++;
        }

        int i = 0;

        while (i < (m - n + 1))
        {
            if (v == u)
            {
                return true;
            }

            u[s2[i] - 'a']--;
            u[s2[i + n] - 'a']++;
            i++;
        }

        return false;
    }
};