#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <unordered_set>
using namespace std;

// class Solution
// {
// public:
//     bool hasSpecialSubstring(string s, int k)
//     {
//         bool judge = false;
//         stack<char> Str;
//         if (s.size() == k)
//         {
//             std::unordered_set<char> uniqueChars;
//             for (char ch : s)
//             {
//                 uniqueChars.insert(ch);
//             }
//             if (uniqueChars.size() > 1)
//             {
//                 return false;
//             }
//             else
//                 return true;
//         }

//         for (int i = 0; i < s.size(); i++)
//         {
//             Str.push(s[i]);
//             for()
//         }
//     }
// };

class Solution
{
public:
    bool hasSpecialSubstring(string s, int k)
    {
        int n = s.size();
        if (k > n)
            return false;

        for (int i = 0; i <= n - k; i++)
        {
            string sub = s.substr(i, k);

            char firstChar = sub[0];
            bool isUniform = true;
            for (char c : sub)
            {
                if (c != firstChar)
                {
                    isUniform = false;
                    break;
                }
            }

            if (isUniform)
            {
                if ((i == 0 || s[i - 1] != firstChar) && (i + k == n || s[i + k] != firstChar))
                {
                    return true;
                }
            }
        }
        return false;
    }
};
