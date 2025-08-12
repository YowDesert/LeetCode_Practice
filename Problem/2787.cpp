#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;
static const int MOD = 1'000'000'007;
// 10 2
//      0   1   2   3   4   5
// 0    1   4   9
// 1    5   10
// 2    13
// 3
// 4
// 5

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