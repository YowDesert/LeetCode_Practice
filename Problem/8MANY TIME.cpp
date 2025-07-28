#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int myAtoi(string s)
    {
        int sum = 0;
        int i = 0;
        int sign = 1;

        while (i < s.size() && s[i] == ' ')
        {
            i++;
        }

        if (i < s.size() && (s[i] == '-' || s[i] == '+'))
        {
            sign = (s[i] == '-') ? -1 : 1;
            i++;
        }

        while (i < s.size() && isdigit(s[i]))
        {
            int digit = s[i] - '0';
            if (sum > INT_MAX / 10 || (sum == INT_MAX / 10 && digit > (sign == 1 ? 7 : 8)))
            {
                return (sign == 1) ? INT_MAX : INT_MIN;
            }
            sum = sum * 10 + digit;
            i++;
        }

        return sum * sign;
    }
};

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int myAtoi(string s)
    {
        int i = 0, n = s.size(), sign = 1, ans = 0;

        // 跳過空格
        while (i < n && s[i] == ' ')
        {
            i++;
        }

        // 處理正負號
        if (i < n && (s[i] == '+' || s[i] == '-'))
        {
            sign = (s[i] == '-') ? -1 : 1;
            i++;
        }

        // 處理數字
        while (i < n && s[i] >= '0' && s[i] <= '9')
        {
            int digit = s[i] - '0';

            // 溢出檢查：如果 `ans * 10 + digit` 會超過 `INT_MAX` 或 `INT_MIN`
            if (ans > (INT_MAX - digit) / 10)
            {
                return (sign == 1) ? INT_MAX : INT_MIN;
            }

            ans = ans * 10 + digit;
            i++;
        }

        return ans * sign;
    }
};
