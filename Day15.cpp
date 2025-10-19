// 3397 Maximum Number of Distinct Elements After Operations

class Solution
{
public:
    int maxDistinctElements(vector<int> &nums, int k)
    {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int need = nums[0] - k, i = 0;
        int res = 0;
        for (i = 0; i < n; i++)
        {
            if (nums[i] - k <= need && need <= nums[i] + k)
            {
                need++;
                res++;
                continue;
            }
            if (need < nums[i] - k)
            {
                need = nums[i] - k;
                need++;
                res++;
            }
        }
        return res;
    }
};