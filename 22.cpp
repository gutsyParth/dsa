class Solution
{
public:
    vector<string> ans;
    void fun(int op, int n, string s)
    {
        if (n == 0)
        {
            for (int i = 0; i < op; i++)
            {
                s += ")";
            }
            ans.push_back(s);
            return;
        }

        fun(op + 1, n - 1, s + "(");
        if (op)
        {
            fun(op - 1, n, s + ")");
        }
    }

    vector<string> generateParenthesis(int n)
    {
        fun(0, n, "");
        return ans;
    }
};