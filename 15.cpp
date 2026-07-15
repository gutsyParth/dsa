#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        sort(nums.begin(), nums.end(), greater<int>());

        int n = nums.size();
        vector<vector<int>> ans;
        for (int i = 0; i < n - 2; i++)
        {
            for (int j = i + 1; j < n - 1; j++)
            {
                int sum = nums[i] + nums[j];
                int idx = lower_bound(nums.begin() + j + 1, nums.end(), -sum, greater<int>()) -
                          nums.begin();

                if (-sum == nums[idx])
                {
                    ans.push_back({nums[i], nums[j], -sum});
                }
            }
        }

        return ans;
    }
};

int main()
{
    Solution S;

    vector<int> v = {-1, 0, 1, 2, -1, -4};

    vector<vector<int>> u = S.threeSum(v);

    for (auto x : u)
    {
        for (auto y : x)
        {
            cout << y << " ";
        }

        cout << "\n";
    }
}