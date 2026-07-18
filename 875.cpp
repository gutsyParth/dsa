class Solution
{
public:
    int minEatingSpeed(vector<int> &piles, int h)
    {
        long long st = 1, en = *max_element(piles.begin(), piles.end());
        long long mid;
        int ans = INT_MAX;
        while (st <= en)
        {
            mid = st + (en - st) / 2;

            long long cur_hr = 0;

            for (auto x : piles)
            {
                cur_hr += (x + mid - 1) / mid;
            }

            if (cur_hr > h)
            {
                st = mid + 1;
            }
            else
            {
                ans = min(ans, mid);
                en = mid - 1;
            }
        }

        return ans;
    }
};