class Solution
{
public:
    vector<vector<int>> generate(int numRows)
    {
        vector<vector<int>> ans(numRows);

        ans[0] = {{1}};

        for (int i = 2; i <= numRows; i++)
        {
            vector<int> temp(i);

            for (int j = 1; j < temp.size() - 1; j++)
            {
                temp[j] = ans[i - 2][j] + ans[i - 2][j - 1];
            }

            temp[0] = 1;
            temp[temp.size() - 1] = 1;

            ans.push_back(temp);
        }

        return ans;
    }
};