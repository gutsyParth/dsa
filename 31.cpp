class Solution
{
public:
    void nextPermutation(vector<int> &nums)
    {
        int n = nums.size();
        int i = n - 1;

        while (i >= 1)
        {
            if (nums[i - 1] < nums[i])
            {
                break;
            }
            i -= 1;
        }

        if (i == 0)
        {
            sort(nums.begin(), nums.end());
            return;
        }

        int num1 = nums[i];
        int num2 = nums[i - 1];
        int idx = i;

        for (int j = i + 1; j < n; j++)
        {
            if (num2 < nums[j])
            {
                num1 = min(num1, nums[j]);
                idx = j;
            }
        }

        swap(nums[i - 1], nums[idx]);
        sort(nums.begin() + i, nums.end());
    }
};