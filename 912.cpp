class Solution
{
public:
    int partition(vector<int> &nums, int st, int en)
    {
        int pivot = nums[en];
        int j = en - 1;
        while (st < en)
        {
            if (nums[st] >= pivot)
            {
                swap(nums[st], nums[j]);
                j--;
            }
            else
            {
                st++;
            }
        }

        swap(nums[st], nums[en]);

        return st - 1;
    }

    vector<int> merge(vector<int> &nums, int st, int en, int pivot)
    {
        vector<int> ans;

        int i = st, j = pivot + 1;

        while (i <= pivot && j <= en)
        {
            if (nums[i] <= nums[j])
            {
                ans.push_back(nums[i]);
            }
            else
            {
                ans.push_back(nums[j]);
            }
        }

        while (i <= pivot)
        {
            ans.push_back(nums[i]);
            i++;
        }

        while (j <= en)
        {
            ans.push_back(nums[j]);
            j++;
        }

        return ans;
    }

    void mergeSort(vector<int> &nums, int st, int en)
    {
        int pivot = partition(nums, st, en);
        mergeSort(nums, st, pivot);
        mergeSort(nums, pivot + 1, en);

        merge(nums, st, en, pivot);
    }

    vector<int> sortArray(vector<int> &nums)
    {
        vector<int> ans = mergeSort(nums, 0, nums.size());

        return ans;
    }
};