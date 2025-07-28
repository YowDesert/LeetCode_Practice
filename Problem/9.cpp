#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    bool isPalindrome(int x)
    {
        string str = to_string(x);
        string PalingromeStr;
        for (int i = str.size() - 1; i >= 0; i--)
        {
            PalingromeStr.push_back(str[i]);
        }
        if (str == PalingromeStr)
        {
            return true;
        }
        else
            return false;
    }
};