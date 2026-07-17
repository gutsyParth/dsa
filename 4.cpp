class Solution
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        int m = nums1.size();
        int n = nums2.size();

        if (n == 0)
        {
            --m;
            if (m % 2)
            {
                return (nums2[m / 2] + nums2[m / 2 + 1]) / 2;
            }
            else
            {
                return nums2[m / 2];
            }
        }
        else if (m == 0)
        {
            --n;
            if (n % 2)
            {
                return (nums2[n / 2] + nums2[n / 2 + 1]) / 2;
            }
            else
            {
                return nums2[n / 2];
            }
        }
        else
        {
            int st1 = 0, en1 = m - 1;
            int mid1;

            int tgt = (m + n - 1) / 2;

            while (st1 <= en1)
            {
                mid1 = st1 + (en1 - st1) / 2;

                int st2 = 0, en2 = n - 1;
                int mid2;

                while (st2 <= en2)
                {
                    mid2 = st2 + (en2 - st2) / 2;

                    if (nums1[mid1] <= nums2[mid2])
                    {
                        st2 = mid2 + 1;
                    }
                    else
                    {
                        en2 = mid2 - 1;
                    }
                }

                int pos = st1 + en2 + 1;

                if (pos < tgt)
                {
                    st1 = mid1 + 1;
                }
                else if (pos > tgt)
                {
                    en1 = mid1 - 1;
                }
            }
        }
    }
};