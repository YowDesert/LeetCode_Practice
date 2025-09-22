#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int canBeTypedWords(string text, string brokenLetters)
    {
        // 建立壞鍵 bitmask：第 i 位代表 'a'+i
        unsigned int bad = 0;
        for (char c : brokenLetters)
            bad |= 1u << (c - 'a');

        int ans = 0;
        bool ok = true; // 當前單字是否可打

        for (char ch : text)
        {
            if (ch == ' ')
            {
                if (ok)
                    ++ans; // 結算前一個單字
                ok = true; // 重置，準備下一個單字
            }
            else if (ok)
            {
                // 如果當前單字仍有效且遇到壞鍵，整個單字失效
                if (bad & (1u << (ch - 'a')))
                    ok = false;
            }
        }
        if (ok)
            ++ans; // 別忘了最後一個單字
        return ans;
    }
};

// class Solution {
// public:
//     int canBeTypedWords(string text, string brokenLetters) {
//         bool bad[26] = {false};
//         for (char c : brokenLetters) bad[c - 'a'] = true;

//         int ans = 0;
//         bool ok = true;

//         for (char ch : text) {
//             if (ch == ' ') {
//                 if (ok) ++ans;
//                 ok = true;
//             } else if (ok && bad[ch - 'a']) {
//                 ok = false;
//             }
//         }
//         if (ok) ++ans;
//         return ans;
//     }
// };

// class Solution
// {
// public:
//     int canBeTypedWords(string text, string brokenLetters)
//     {
//         unordered_set<char> bad(brokenLetters.begin(), brokenLetters.end());
//         bool ok = true; // 目前這個單字是否可打
//         int ans = 0;

//         for (char c : text)
//         {
//             if (c == ' ')
//             {
//                 if (ok)
//                     ++ans; // 遇到空白，結算前一個單字
//                 ok = true; // 重設，準備下一個單字
//             }
//             else
//             {
//                 if (ok && bad.count(c))
//                     ok = false; // 只要有一個壞鍵，整個單字失效
//             }
//         }
//         if (ok)
//             ++ans; // 別忘了最後一個單字
//         return ans;
//     }
// };
