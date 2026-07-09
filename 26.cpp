class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        int last = -101;
        int ans = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] != last)
            {
                nums[ans] = nums[i];
                ans += 1;
                last = nums[i];
            }
        }
        return ans;
    }
};