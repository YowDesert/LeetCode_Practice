#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    string shortestCommonSupersequence(string str1, string str2)
    {
        if (str2.size() < str1.size())
        {
            swap(str1, str2);
        }
    }
};