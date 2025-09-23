// 165 Compare Version Numbers

class Solution
{
public:
    int compareVersion(string version1, string version2)
    {
        stringstream ss1(version1);
        string num1;
        stringstream ss2(version2);
        string num2;
        while (true)
        {
            bool got1 = (bool)getline(ss1, num1, '.');
            bool got2 = (bool)getline(ss2, num2, '.');

            if (!got1 && !got2)
                break;

            if (got1 && got2)
            {
                int val1 = stoi(num1);
                int val2 = stoi(num2);
                if (val1 < val2)
                    return -1;
                if (val1 > val2)
                    return 1;
            }
            else if (got1)
            {
                int val1 = stoi(num1);
                if (val1 != 0)
                    return 1;
            }
            else
            {
                int val2 = stoi(num2);
                if (val2 != 0)
                    return -1;
            }
        }
        return 0;
    }
};