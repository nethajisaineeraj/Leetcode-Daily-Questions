// 417 Pacific Atlantic Water Flow
class Solution
{
public:
    int m, n;
    vector<vector<int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    void bfs(int i, int j, vector<vector<int>> &heights, vector<vector<bool>> &visited)
    {
        queue<pair<int, int>> q;
        q.push({i, j});
        visited[i][j] = true;
        pair<int, int> curr;
        while (!q.empty())
        {
            curr = q.front();
            q.pop();
            for (auto &d : directions)
            {
                int x = curr.first + d[0];
                int y = curr.second + d[1];

                if (x < 0 || x >= m || y < 0 || y >= n)
                    continue;
                if (visited[x][y])
                    continue;
                if (heights[x][y] < heights[curr.first][curr.second])
                    continue;

                visited[x][y] = true;
                q.push({x, y});
            }
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>> &heights)
    {
        this->m = heights.size();
        this->n = heights[0].size();

        vector<vector<bool>> pacific(m, vector<bool>(n, false));
        vector<vector<bool>> atlantic(m, vector<bool>(n, false));

        for (int j = 0; j < n; j++)
            bfs(0, j, heights, pacific);
        for (int i = 0; i < m; i++)
            bfs(i, 0, heights, pacific);
        for (int i = 0; i < m; i++)
            bfs(i, n - 1, heights, atlantic);
        for (int j = 0; j < n; j++)
            bfs(m - 1, j, heights, atlantic);

        vector<vector<int>> res;

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (pacific[i][j] && atlantic[i][j])
                    res.push_back({i, j});
            }
        }

        return res;
    }
};