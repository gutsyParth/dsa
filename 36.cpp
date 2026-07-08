class Solution
{
public:
    bool isValidSudoku(vector<vector<char>> &board)
    {
        for (int i = 0; i < 9; i++)
        {
            vector<int> count(10);

            for (int j = 0; j < 9; j++)
            {
                if (board[i][j] != '.')
                {
                    if (count[board[i][j] - '0'])
                    {
                        return false;
                    }
                    count[board[i][j] - '0']++;
                }
            }

            fill(count.begin(), count.end(), 0);

            for (int j = 0; j < 9; j++)
            {
                if (board[j][i] != '.')
                {
                    if (count[board[j][i] - '0'])
                    {
                        return false;
                    }
                    count[board[j][i] - '0']++;
                }
            }
        }

        vector<vector<int>> counts(9, vector<int>(9));

        for (int i = 0; i < 81; i++)
        {
            int row = i / 9;
            int col = i % 9;
            if (board[i / 9][i % 9] != '.')
            {
                counts[(row / 3) * 3 + col / 3][board[i / 9][i % 9] - '0'] += 1;
            }
        }

        for (auto x : counts)
        {
            for (auto y : x)
            {
                if (y > 1)
                {
                    return false;
                }
            }
        }

        return true;
    }
};