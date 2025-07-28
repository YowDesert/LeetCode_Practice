#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int maxDiff(int num)
    {
        string s = to_string(num);

        string a = s;
        for (char c : s)
        {
            if (c != '9')
            {
                char from = c;
                for (char &ch : a)
                {
                    if (ch == from)
                        ch = '9';
                }
                break;
            }
        }

        string b = s;
        if (s[0] != '1')
        {
            // 把第一個數字換成 '1'（避免 leading zero）
            char from = s[0];
            for (char &ch : b)
            {
                if (ch == from)
                    ch = '1';
            }
        }
        else
        {
            // 把第一個不是 0 或 1 的數字換成 0
            for (int i = 1; i < b.size(); ++i)
            {
                if (b[i] != '0' && b[i] != '1')
                {
                    char from = b[i];
                    for (char &ch : b)
                    {
                        if (ch == from)
                            ch = '0';
                    }
                    break;
                }
            }
        }

        int maxVal = stoi(a);
        int minVal = stoi(b);

        return maxVal - minVal;
    }
};

int main()
{
    Solution Sol;
    int num = 555;
    cout << Sol.maxDiff(num);
}