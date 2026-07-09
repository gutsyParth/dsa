class Solution
{
public:
    int removeElement(vector<int> &nums, int val)
    {
        int n = nums.size();

        int ptr = n - 1;

        int i = 0;

        while (i <= ptr)
        {
            if (nums[i] == val)
            {
                swap(nums[i], nums[ptr]);
                ptr -= 1;
            }
            else
            {
                i++;
            }
        }

        return ptr + 1;
    }
};