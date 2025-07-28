#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int Stairs(int n, int dp[])
    {
        if (n == 3)
        {
            dp[3] = dp[1] + dp[2];
            return dp[3];
        }
        Stairs(n - 1, dp);
        dp[n] = dp[n - 1] + dp[n - 2];
        return dp[n];
    }
    int climbStairs(int n)
    {
        int dp[50] = {0};
        dp[1] = 1;
        dp[2] = 2;
        if (n <= 2)
        {
            return dp[n];
        }
        Stairs(n, dp);
        return dp[n];
    }
};

int main()
{
    Solution sol;
    cout << sol.climbStairs(35);
}