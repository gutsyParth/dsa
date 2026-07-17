#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    bool search(vector<int> &nums, int target)
    {
        int st = 0;

        int n = nums.size();

        for (int i = 0; i < n - 1; i++)
        {
            if (nums[i] > nums[i + 1])
            {
                st = i + 1;
                break;
            }
        }

        int en = st + n - 1;

        int mid;

        while (st <= en)
        {
            mid = st + (en - st) / 2;

            int idx = mid % n;

            cout << mid << "\n";

            if (nums[idx] == target)
            {
                return idx;
            }
            else if (nums[idx] < target)
            {
                st = mid + 1;
            }
            else
            {
                en = mid - 1;
            }
        }
        cout << nums[idx] << " " << target << "\n";

        return -1;
    }
};

int main()
{
    Solution S;
    vector<int> v = {2, 5, 6, 0, 0, 1, 2};
    cout << S.search(v, 3) << "####";
}