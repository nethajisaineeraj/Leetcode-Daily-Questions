// 3370 Smallest Number With All Set Bits
class Solution
{
public:
    int smallestNumber(int n)
    {
        int result = 0;
        int i = 1;
        while (n != 0)
        {
            result += i;
            i *= 2;
            n = n >> 1;
        }
        return result;
    }
};