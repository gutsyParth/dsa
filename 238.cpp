class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        vector<int> left(nums.size());
        vector<int> right(nums.size());
        int n = nums.size();

        left[0] = 1;
        right[n - 1] = 1;

        for (int i = n - 1; i >= 0; i--)
        {
            if (i == n - 1)
            {
                right[i] = 1;
            }
            else if (i == n - 2)
            {
                right[i] = nums[i + 1];
            }
            else
            {
                right[i] = nums[i + 1] * right[i + 2];
            }
        }

        for (int i = 0; i < n; i++)
        {
            if (i == 0)
            {
                left[0] = 1;
            }
            else if (i == 1)
            {
                left[i] = nums[i - 1];
            }
            else
            {
                left[i] = nums[i - 1] * left[i - 2];
            }
        }

        vector<int> ans;

        for (int i = 0; i < n; i++)
        {
            ans.push_back(left[i] * right[i]);
        }

        return ans;
    }
};