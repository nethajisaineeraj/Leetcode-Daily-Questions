// 120 Triangle
class Solution
{
public:
    int minimumTotal(vector<vector<int>> &triangle)
    {
        int m = triangle.size();
        for (int i = (m - 1); i > 0; i--)
        {
            int n = triangle[i].size();
            for (int p = 0; p < (n - 1); p++)
            {
                triangle[i - 1][p] = min(triangle[i][p], triangle[i][p + 1]) + triangle[i - 1][p];
            }
        }
        return triangle[0][0];
    }
};