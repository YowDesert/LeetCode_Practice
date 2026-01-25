#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string fractionToDecimal(int numerator, int denominator)
    {
        if (numerator == 0)
            return "0"; // 特例：結果為 0

        string ans;
        long long n = numerator, d = denominator;

        // ✅ 處理負號 (一正一負才加負號)
        if ((n < 0) ^ (d < 0))
            ans.push_back('-');

        // 轉成正數避免 overflow
        n = llabs(n);
        d = llabs(d);

        // ✅ 整數部分
        ans += to_string(n / d);

        long long remainder = n % d;
        if (remainder == 0)
            return ans; // 無小數部分，直接回傳

        ans.push_back('.');

        // ✅ 紀錄每個餘數第一次出現的位置（用來插入括號）
        unordered_map<long long, int> seen; // remainder -> 字串中的 index

        while (remainder != 0)
        {
            if (seen.count(remainder))
            {
                // 找到循環開始位置 → 插入 "("
                ans.insert(seen[remainder], "(");
                ans.push_back(')');
                break;
            }

            seen[remainder] = ans.size(); // 記錄當前餘數的位置
            remainder *= 10;
            ans += to_string(remainder / d);
            remainder %= d;
        }

        return ans;
    }
};