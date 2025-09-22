#include <bits/stdc++.h>

using namespace std;

#include <bits/stdc++.h>
using namespace std;

class Solution
{
    static inline bool isVowel(char c)
    {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
    static string lowerStr(string s)
    {
        for (char &c : s)
            c = tolower(c);
        return s;
    }
    static string devowel(string s)
    {
        for (char &c : s)
        {
            c = tolower(c);
            if (isVowel(c))
                c = '*';
        }
        return s;
    }

public:
    vector<string> spellchecker(vector<string> &wordlist, vector<string> &queries)
    {
        unordered_set<string> exact(wordlist.begin(), wordlist.end());

        unordered_map<string, string> caseMap;  // lower -> first original
        unordered_map<string, string> vowelMap; // devowel(lower) -> first original

        caseMap.reserve(wordlist.size() * 2);
        vowelMap.reserve(wordlist.size() * 2);

        for (const string &w : wordlist)
        {
            string lw = lowerStr(w);
            if (!caseMap.count(lw))
                caseMap[lw] = w;

            string vw = devowel(w);
            if (!vowelMap.count(vw))
                vowelMap[vw] = w;
        }

        vector<string> ans;
        ans.reserve(queries.size());
        for (const string &q : queries)
        {
            if (exact.count(q))
            {
                ans.push_back(q);
                continue;
            }

            string lq = lowerStr(q);
            auto it1 = caseMap.find(lq);
            if (it1 != caseMap.end())
            {
                ans.push_back(it1->second);
                continue;
            }

            string vq = devowel(q);
            auto it2 = vowelMap.find(vq);
            if (it2 != vowelMap.end())
            {
                ans.push_back(it2->second);
                continue;
            }

            ans.push_back("");
        }
        return ans;
    }
};

int main()
{
    Solution sol;
    vector<string> wordlist;
    vector<string> queries;
    wordlist = {"KiTe", "kite", "hare", "Hare"}, queries = {"kite", "Kite", "KiTe", "Hare", "HARE", "Hear", "hear", "keti", "keet", "keto"};
    for (int i = 0; i < queries.size(); i++)
        cout << sol.spellchecker(wordlist, queries)[i] << endl;
}