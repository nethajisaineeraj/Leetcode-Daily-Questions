// 966 Vowel Spellchecker

class Solution
{
public:
    set<string> exactMatch;
    map<string, string> lowerCase;
    map<string, string> deVowel;

    string replaceVowels(string word)
    {
        int wordLength = word.size();
        string res = "";
        for (int i = 0; i < wordLength; i++)
        {
            char ch = word[i];
            if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
                res += "*";
            else
                res += ch;
        }
        return res;
    }

    string changeToLower(string word)
    {
        int wordLength = word.size();
        string res = "";
        for (int i = 0; i < wordLength; i++)
        {
            res += tolower(word[i]);
        }
        return res;
    }

    vector<string> spellchecker(vector<string> &wordlist, vector<string> &queries)
    {
        for (auto word : wordlist)
        {
            exactMatch.insert(word);

            string lowerWord = changeToLower(word);
            if (lowerCase.find(lowerWord) == lowerCase.end())
            {
                lowerCase[lowerWord] = word;
            }

            string novowelWord = replaceVowels(lowerWord);
            if (deVowel.find(novowelWord) == deVowel.end())
            {
                deVowel[novowelWord] = word;
            }
        }
        vector<string> ans;
        for (auto query : queries)
        {
            if (exactMatch.find(query) != exactMatch.end())
            {
                ans.push_back(query);
                continue;
            }

            string lowerWord = changeToLower(query);
            if (lowerCase.find(lowerWord) != lowerCase.end())
            {
                ans.push_back(lowerCase[lowerWord]);
                continue;
            }

            string novowelWord = replaceVowels(lowerWord);
            if (deVowel.find(novowelWord) != deVowel.end())
            {
                ans.push_back(deVowel[novowelWord]);
                continue;
            }

            ans.push_back("");
        }

        return ans;
    }
};