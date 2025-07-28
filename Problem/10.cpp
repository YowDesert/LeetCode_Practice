//* 可以是前面一個東西或是都不是
#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    bool isMatch(string s, string p)
    {
        if (s.size() != p.size())
        {
            return false;
        }
        // unordered_map<char, int> smap;
        // unordered_map<char, int> pmap;
        // for (int i = 0; i < smap.size(); i++)
        // {
        //     smap[s[i]] += 1;
        // }
        for (int i = 0; i < p.size(); i++)
        {
            if (s[i] == p[i])
            {
                continue;
            }
            else if (s[i] != 0 && p[i] == '*')
            {
                continue;
            }
            else if (p[i] == '.')
            {
                continue;
            }
            else if (p[i] == '*' && p[i - 1] == '.')
            {
                continue;
            }
            else if (p[i] == '*' && s[i] == p[i - 1])
            {
                continue;
            }
            return false;
        }
        return true;
    }
};