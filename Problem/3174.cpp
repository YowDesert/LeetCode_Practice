// beats 100% too
#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    string clearDigits(string s)
    {
        int Ssize = s.size();
        for (int i = 0; i < Ssize; i++)
        {
            if (s[i] >= '0' && s[i] <= '9')
            {
                if (i != 0)
                    s.erase(i - 1, 2);
                else
                    s.erase(i);
                i -= 2;
                Ssize -= 2;
                if (i < 0)
                {
                    i = 0;
                }
            }
        }
        return s;
    }
};