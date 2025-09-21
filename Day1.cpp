// 3541 Find Most Frequent Vowel and Consonant
class Solution
{
public:
    int maxFreqSum(string s)
    {
        unordered_map<char, int> m;
        int maxVowel = 0;
        int maxConsonant = 0;
        for (auto ch : s)
        {
            m[ch]++;
            if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
            {
                maxVowel = max(maxVowel, m[ch]);
            }
            else
            {
                maxConsonant = max(maxConsonant, m[ch]);
            }
        }
        return maxVowel + maxConsonant;
    }
};