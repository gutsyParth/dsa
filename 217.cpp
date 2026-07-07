class Solution
{
public:
    bool containsDuplicate(vector<int> &nums)
    {
        unordered_map<int, int> mp;

        for (auto x : nums)
        {
            if (mp.count(x))
            {
                return true;
            }
            mp[x] = 1;
        }

        return false;
    }
};