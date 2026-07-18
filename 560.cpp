class Solution
{
public:
    int subarraySum(vector<int> &nums, int k)
    {
        int st = 0, en = 0;
        int ans = 0;
        int cur_sum = 0;
        while (st <= en)
        {
            if (cur_sum + nums[en] > k)
            {
                cur_sum -= nums[st];
                st += 1;
            }
            else if (cur_sum + nums[en] < k)
            {
                cur_sum += nums[en];
                en += 1;
            }
            else
            {
                ans += 1;
                cur_sum -= nums[st];
                st += 1;
            }
        }

        return ans;
    }
};