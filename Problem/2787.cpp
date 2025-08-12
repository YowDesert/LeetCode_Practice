#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;
static const int MOD = 1'000'000'007;

//
// 為什麼 dp[0] = 1？
// dp[0] = 1 代表「湊出 0」有一種方法，就是不選任何數字。

// 這是 DP 初始化的基礎。

class Solution
{
public:
    int numberOfWays(int n, int x)
    {
        vector<int> powers;
        for (int i = 1;; ++i)
        {
            long long p = 1;
            for (int k = 0; k < x; ++k)
                p *= i;
            if (p > n)
                break;
            powers.push_back((int)p);
        }

        vector<long long> dp(n + 1, 0);
        dp[0] = 1;
        for (int p : powers)
        {
            for (int s = n; s >= p; --s)
            {
                dp[s] = (dp[s] + dp[s - p]) % MOD;
            }

            for (int i = 0; i < n + 1; i++)
            {
                cout << dp[i] << " ";
            }
            cout << endl;
        }
        return (int)dp[n];
    }
};

int main()
{
    Solution sol;
    int n, x;
    n = 4;
    x = 1;
    cout << sol.numberOfWays(n, x) << endl;
}