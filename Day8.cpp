// 3005 Count Elements With Maximum Frequency

class Solution
{
public:
    int maxFrequencyElements(vector<int> &nums)
    {
        int n = nums.size();
        if (n <= 1)
            return n;
        sort(nums.begin(), nums.end());
        int frequency = 1;
        int maxFrequency = 0;
        int count = 0;
        for (int i = 1; i < n; i++)
        {
            if (nums[i] == nums[i - 1])
            {
                frequency++;
            }
            else
            {
                if (maxFrequency == frequency)
                    count++;
                else if (maxFrequency < frequency)
                {
                    count = 1;
                    maxFrequency = frequency;
                }
                frequency = 1;
            }
        }
        if (maxFrequency == frequency)
            count++;
        else if (maxFrequency < frequency)
        {
            count = 1;
            maxFrequency = frequency;
        }
        return count * maxFrequency;
    }
};