class Solution
{
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        int i = 0, j = 0, k = m;

        while (i < m && j < n)
        {
            if (nums1[i] <= nums2[j])
            {
                nums1[k] = nums1[i];
                k += 1;
                k = k % (m + n);
                i += 1;
            }
            else
            {
                nums1[k] = nums2[j];
                k += 1;
                k = k % (m + n);
                j += 1;
            }
        }

        while (i < m)
        {
            nums1[k] = nums1[i];
            k += 1;
            k = k % (m + n);
            i += 1;
        }

        while (j < n)
        {
            nums1[k] = nums2[j];
            k += 1;
            k = k % (m + n);
            j += 1;
        }

        rotate(nums1.begin(), nums1.begin() + m, nums1.end());
    }
};