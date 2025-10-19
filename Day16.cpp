// 1625 Lexicographically Smallest String After Applying Operations
class Solution
{
public:
    unordered_set<string> visited;
    string ans;
    string add(string s, int a)
    {
        int n = s.size();
        string res = "";
        for (int i = 0; i < n; i++)
        {
            i % 2 != 0 ? res += (((s[i] - '0') + a) % 10 + '0') : res += s[i];
        }
        return res;
    }
    string rotateRight(string s, int b)
    {
        int n = s.size();
        return s.substr(n - b) + s.substr(0, n - b);
    }
    void dfs(int a, int b, string s)
    {
        if (visited.find(s) != visited.end())
            return;
        visited.insert(s);
        ans = min(ans, s);
        dfs(a, b, add(s, a));
        dfs(a, b, rotateRight(s, b));
    }
    string findLexSmallestString(string s, int a, int b)
    {
        ans = s;
        dfs(a, b, s);
        return ans;
    }
};
