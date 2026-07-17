class Solution
{
public:
    int mySqrt(int x)
    {
        int st = 1, en = (x + 1) / 2;

        int mid;

        while (st <= en)
        {
            mid = st + (en - st) / 2;

            if (mid * mid < x)
            {
                st = mid + 1;
            }
            else if (mid * mid > x)
            {
                en = mid - 1;
            }
            else
            {
                break;
            }
        }

        return en;
    }
};