// 2011 Final Value of Variable After Performing Operations
class Solution
{
public:
    int finalValueAfterOperations(vector<string> &operations)
    {
        int x = 0;
        for (auto oper : operations)
        {
            if (oper == "++X" or oper == "X++")
                x++;
            else
                x--;
        }
        return x;
    }
};