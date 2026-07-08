class Solution
{
public:
    void sortColors(vector<int> &nums)
    {
        int beg = 0, md = 0, en = nums.size() - 1;

        while (md < nums.size())
        {
            if (nums[md] == 0)
            {
                swap(nums[md], nums[beg]);
                md++, beg++;
            }
            else if (nums[md] == 1)
            {
                md++;
            }
            else
            {
                swap(nums[md], nums[en]);
                en--;
            }
        }
    }
};