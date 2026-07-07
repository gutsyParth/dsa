class Solution
{
public:
    bool containsNearbyDuplicate(vector<int> &nums, int k)
    {
        unordered_map<int, int> mp;
        const int N = nums.size();

        for (int i = 0; i < N; i++)
        {
            if (mp.count(nums[i]))
            {
                if (i - mp[nums[i]] <= k)
                {
                    return true;
                }
            }
            mp[nums[i]] = i;
        }
        return false;
    }
};