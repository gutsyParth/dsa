class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int m = matrix.size();
        int n = matrix[0].size();

        int st = 0, en = m * n - 1;
        int mid;
        while (st <= en)
        {
            mid = st + (en - st) / 2;
            int row = mid / n;
            int col = mid % m;

            if (matrix[row][col] == target)
            {
                return true;
            }
            else if (matrix[row][col] < target)
            {
                st = mid + 1;
            }
            else
            {
                en = mid - 1;
            }
        }

        return false;
    }
};