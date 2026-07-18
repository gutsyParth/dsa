class Solution
{
public:
    int fun(vector<int> &nums1, vector<int> &nums2, int idx)
    {
        int st1 = 0, en1 = nums1.size() - 1;
        int mid1;

        while (st1 <= en1)
        {
            mid1 = st1 + (en1 - st1) / 2;

            int st2 = 0, en2 = nums2.size() - 1;
            int mid2;

            while (st2 <= en2)
            {
                mid2 = st2 + (en2 - st2) / 2;

                if (nums2[mid2] < nums1[mid1])
                {
                    st2 = mid2 + 1;
                }
                else if (nums2[mid2] > nums1[mid1])
                {
                    en2 = mid2 - 1;
                }
                else
                {
                                }
            }
        }
    }

    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        int m = nums1.size();
        int n = nums2.size();

        if ((m + n) % 2)
        {
            return fun(nums1, nums2, (m + n - 1) / 2) / 2;
        }
        else
        {
            return (fun(nums1, nums2, (m + n - 1) / 2) + fun(nums1, nums2, (m + n - 1) / 2 + 1)) / 2;
        }
    }
};