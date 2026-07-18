#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

class Solution
{
public:
    int splitArray(vector<int> &nums, int k)
    {
        int st = *max_element(nums.begin(), nums.end());
        int en = accumulate(nums.begin(), nums.end(), 0);

        int mid;
        int ans = INT_MAX;
        while (st <= en)
        {
            mid = st + (en - st) / 2;
            int cur_sum = 0;
            int split = 1;
            int cur_ans = 0;

            for (auto x : nums)
            {
                if (x + cur_sum > mid)
                {
                    cur_sum = 0;
                    split += 1;
                }
                cur_sum += x;
                cur_ans = max(cur_ans, cur_sum);
            }

            cout << mid << " " << k << " " << split << " " << cur_ans << "\n";

            if (split < k)
            {
                en = mid - 1;
            }
            else if (split > k)
            {
                st = mid + 1;
            }
            else
            {
                en = mid - 1;
                ans = min(ans, cur_ans);
            }
        }
        return ans;
    }
};

int main()
{
    Solution S;
    vector<int> v = {5, 5, 5, 5};
    S.splitArray(v, 3);
}