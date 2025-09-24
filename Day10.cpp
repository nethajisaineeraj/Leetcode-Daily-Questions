// 166 Fraction to Recurring Decimal
class Solution
{
public:
    string fractionToDecimal(int numerator, int denominator)
    {
        if (numerator == 0)
            return "0";
        string result;
        // Handling sign
        if ((numerator < 0) ^ (denominator < 0))
            result += '-';
        // Converting to long long to prevent overflow & taking abs
        // llabs() -> ll means it takes long long input for abs and produce long long ouput
        long long n = llabs((long long)numerator);
        long long d = llabs((long long)denominator);
        // Integer part
        result += to_string(n / d);
        long long rem = n % d;
        if (rem == 0)
            return result;
        result += '.';
        unordered_map<long, int> pos;
        while (rem)
        {
            if (pos.count(rem))
            {
                result.insert(pos[rem], 1, '(');
                result += ')';
                break;
            }
            pos[rem] = result.size();
            rem *= 10;
            result += to_string(rem / d);
            rem %= d;
        }
        return result;
    }
};