#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int findMin(vector<int> &nums)
    {
        int n = nums.size();

        int st = 0, en = n - 1;
        int mid;
        while (st <= en)
        {
            mid = st + (en - st) / 2;
            cout << mid << "\n";
            if (nums[mid] > nums[st])
            {
                st = mid;
            }
            else if (nums[mid] < nums[en])
            {
                en = mid;
            }
            else
            {
                return nums[en];
            }
        }

        return -1;
    }
};

int main()
{
    vector<int> v = {3, 4, 5, 1, 2};

    Solution S;
    S.findMin(v);
}