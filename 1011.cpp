class Solution
{
public:
    int shipWithinDays(vector<int> &weights, int days)
    {
        int st = *max_element(weights.begin(), weights.end());

        int en = accumulate(weights.begin(), weights.end(), 0);

        int mid;

        int ans = INT_MAX;
        while (st <= en)
        {
            mid = st + (en - st) / 2;
            int cur = 1;
            int num_days = 0;
            for (int i = 0; i < weights.size(); i++)
            {
                if (cur + weights[i] > mid)
                {
                    cur = 0;
                    num_days += 1;
                }
                cur += weights[i];
            }

            if (num_days <= days)
            {
                ans = min(ans, mid);
                en = mid - 1;
            }
            else if (num_days > days)
            {
                st = mid + 1;
            }
        }

        return ans;
    }
};