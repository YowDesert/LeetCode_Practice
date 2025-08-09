#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <iomanip>
#include <random>

using namespace std;

double dp[201][201];
class Solution
{
public:
    double soup(int A, int B)
    {
        if (A <= 0 && B <= 0)
            return 0.5;
        if (A <= 0)
            return 1;
        if (B <= 0)
            return 0;

        if (dp[A][B] != -1)
            return dp[A][B];

        dp[A][B] = 0.25 * (soup(A - 100, B) + soup(A - 75, B - 25) + soup(A - 50, B - 50) + soup(A - 25, B - 75));
        return dp[A][B];
    }

    double soupServings(int n)
    {
        if (n >= 4800)
            return 1;
        int New_n = ceil(n / 25);
        return dp[New_n][New_n] = soup(New_n, New_n);
    }
};

int main()
{
    Solution sol;
    cout << fixed << setprecision(5) << sol.soupServings(50) << endl; // Example usage
    return 0;
}