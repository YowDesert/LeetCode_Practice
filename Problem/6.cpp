#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    string convert(string s, int numRows)
    {
        vector<char> ConvertStr[numRows];
        bool increse = true;
        int num = 0;
        for (int i = 0; i < s.length(); i++)
        {
            if (increse)
            {
                ConvertStr[num].push_back(s[i]);
                if (num == numRows - 1)
                {
                    increse = false;
                    num--;
                }
                else
                {
                    num++;
                }
            }
            else
            {
                ConvertStr[num].push_back(s[i]);
                if (num == 0)
                {
                    increse = true;
                    num++;
                }
                else
                {
                    num--;
                }
            }
        }
        string AnsStr;
        for (int i = 0; i < numRows - 1; i++)
        {
            for (int j = 0; j < ConvertStr[i].size(); j++)
            {
                AnsStr.push_back(ConvertStr[i][j]);
            }
        }
        return AnsStr;
    }
};