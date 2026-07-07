class Codec
{
public:
    // Encodes a list of strings to a single string.
    string encode(vector<string> &strs)
    {
        string ans = "";

        for (auto x : strs)
        {
            ans += "#" + x;
        }

        return ans;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s)
    {
        vector<string> ans;

        int i = 0;
        int n = s.size();

        while (i < n)
        {
            string temp = "";

            i += 1;
            while (i < n && s[i] != '#')
            {
                temp += s[i];
                i += 1;
            }

            ans.push_back(temp);
        }

        return ans;
    }
};