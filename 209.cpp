class Solution
{
public:
    int minSubArrayLen(int target, vector<int> &nums)
    {
        int n = nums.size();

        int cur_sum = 0;
        int ans = INT_MAX;
        int j = 0;
        for (int i = 0; i < n; i++)
        {
            cur_sum += nums[i];

            while (j <= i && cur_sum >= target)
            {
                ans = min(ans, i - j + 1);
                cur_sum -= nums[j];
                j += 1;
            }
        }

        if (ans == INT_MAX)
        {
            return 0;
        }
        return ans;
    }
};