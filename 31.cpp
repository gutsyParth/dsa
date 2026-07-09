class Solution
{
public:
    void nextPermutation(vector<int> &nums)
    {
        int i = nums.size() - 1;

        while (i >= 1)
        {
            if (nums[i - 1] < nums[i])
            {
                swap(nums[i - 1], nums[i]);
                return;
            }
            i -= 1;
        }

        sort(nums.begin(), nums.end(), greater<int>());
    }
};