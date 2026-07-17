class Solution
{
public:
    int singleNonDuplicate(vector<int> &nums)
    {
        int n = nums.size();

        int st = 0, en = n - 1;

        int mid;

        while (st <= en)
        {
            mid = st + (en - st) / 2;

            if (mid % 2)
            {
                if (nums[mid] == nums[mid + 1])
                {
                    st = mid + 1;
                }
                else
                {
                    en = mid - 1;
                }
            }
            else
            {
                if (nums[mid] == nums[mid + 1])
                {
                    st = mid + 2;
                }
                else
                {
                    en = mid - 2;
                }
            }
        }

        return nums[en];
    }
};