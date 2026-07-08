class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        set<int> st(nums.begin(), nums.end());
        vector<int> arr(st.begin(), st.end());

        int ans = 1;
        for (int i = 0; i < arr.size() - 1; i++)
        {
            int cnt = 1;
            while (i + 1 < arr.size() && arr[i] + 1 == arr[i + 1])
            {
                cnt += 1;
                i += 1;
            }
            ans = max(ans, cnt);
        }

        return ans;
    }
};