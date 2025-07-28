// Manacher's Algorithm 馬拉車算法 詳見YT
// beats 96%
#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    std::string longestPalindrome(std::string s)
    {
        if (s.length() <= 1)
        {
            return s;
        }

        int maxLen = 1;
        std::string maxStr = s.substr(0, 1);
        s = "#" + std::regex_replace(s, std::regex(""), "#") + "#";
        std::vector<int> dp(s.length(), 0);
        int center = 0;
        int right = 0;

        for (int i = 0; i < s.length(); ++i)
        {
            if (i < right)
            {
                dp[i] = std::min(right - i, dp[2 * center - i]);
            }

            while (i - dp[i] - 1 >= 0 && i + dp[i] + 1 < s.length() && s[i - dp[i] - 1] == s[i + dp[i] + 1])
            {
                dp[i]++;
            }

            if (i + dp[i] > right)
            {
                center = i;
                right = i + dp[i];
            }

            if (dp[i] > maxLen)
            {
                maxLen = dp[i];
                maxStr = s.substr(i - dp[i], 2 * dp[i] + 1);
                maxStr.erase(std::remove(maxStr.begin(), maxStr.end(), '#'), maxStr.end());
            }
        }

        return maxStr;
    }
};

// DP beat 41.15%
class Solution
{
public:
    std::string longestPalindrome(std::string s)
    {
        if (s.length() <= 1)
        {
            return s;
        }

        int max_len = 1;
        int start = 0;
        int end = 0;
        std::vector<std::vector<bool>> dp(s.length(), std::vector<bool>(s.length(), false));

        for (int i = 0; i < s.length(); ++i)
        {
            dp[i][i] = true;
            for (int j = 0; j < i; ++j)
            {
                if (s[j] == s[i] && (i - j <= 2 || dp[j + 1][i - 1]))
                {
                    dp[j][i] = true;
                    if (i - j + 1 > max_len)
                    {
                        max_len = i - j + 1;
                        start = j;
                        end = i;
                    }
                }
            }
        }

        return s.substr(start, end - start + 1);
    }
};

// Expand Around Center beat 81.62%

class Solution
{
public:
    std::string longestPalindrome(std::string s)
    {
        if (s.length() <= 1)
        {
            return s;
        }

        auto expand_from_center = [&](int left, int right)
        {
            while (left >= 0 && right < s.length() && s[left] == s[right])
            {
                left--;
                right++;
            }
            return s.substr(left + 1, right - left - 1);
        };

        std::string max_str = s.substr(0, 1);

        for (int i = 0; i < s.length() - 1; i++)
        {
            std::string odd = expand_from_center(i, i);
            std::string even = expand_from_center(i, i + 1);

            if (odd.length() > max_str.length())
            {
                max_str = odd;
            }
            if (even.length() > max_str.length())
            {
                max_str = even;
            }
        }

        return max_str;
    }
};
