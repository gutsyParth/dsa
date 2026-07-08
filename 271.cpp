class Codec
{
public:
    // Encodes a list of strings to a single string.
    string encode(vector<string> &strs)
    {
        string ans = to_string(strs.size()) + "#";

        for (auto x : strs)
        {
            ans += x.size() + "#";
        }

        for (auto x : strs)
        {
            ans += x;
        }

        return ans;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s)
    {
        int how_many = 0;

        int i = 0;

        while (s[i] != '#')
        {
            how_many = how_many * 10 + (s[i] - '0');

            i += 1;
        }

        vector<string> ans;
        vector<int> lengths;

        while (how_many)
        {
            i += 1;

            int count = 0;

            while (s[i] != '#')
            {
                count = count * 10 + (s[i] - '0');
                i += 1;
            }

            lengths.push_back(count);

            how_many--;
        }

        i += 1;

        for (auto x : lengths)
        {
            string temp = "";
            for (int j = i; j < i + x; j++)
            {
                temp += s[j];
            }

            ans.push_back(temp);

            i += x;
        }

        return ans;
    }
};