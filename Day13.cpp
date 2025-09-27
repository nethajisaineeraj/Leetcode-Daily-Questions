// 812 Largest Triangle Area
class Solution
{
public:
    double largestTriangleArea(vector<vector<int>> &points)
    {
        double maxArea = 0.0;
        int n = points.size();

        for (int i = 0; i < n; i++)
        {
            int a0 = points[i][0];
            int a1 = points[i][1];
            for (int j = i + 1; j < n; j++)
            {
                int b0 = points[j][0];
                int b1 = points[j][1];
                for (int k = j + 1; k < n; k++)
                {
                    int c0 = points[k][0];
                    int c1 = points[k][1];
                    double area = 0.5 * abs((b0 - a0) * (c1 - a1) - (b1 - a1) * (c0 - a0));
                    maxArea = max(maxArea, area);
                }
            }
        }
        return maxArea;
    }
};