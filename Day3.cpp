// 1935 Maximum Number of Words You Can Type

class Solution
{
public:
    int canBeTypedWords(string text, string brokenLetters)
    {
        stringstream ss(text);
        string word;
        vector<string> wordsList;
        while (getline(ss, word, ' '))
        {
            wordsList.push_back(word);
        }
        int n = wordsList.size();
        int m = brokenLetters.size();
        if (m == 0)
            return n;
        bool arr[26] = {false};
        for (auto ch : brokenLetters)
        {
            arr[ch - 97] = true;
        }
        int count = 0;
        for (auto word : wordsList)
        {
            bool isPossible = true;
            for (auto ch : word)
            {
                if (arr[ch - 97])
                {
                    isPossible = false;
                    break;
                }
            }
            if (isPossible)
            {
                count++;
            }
        }
        return count;
    }
};