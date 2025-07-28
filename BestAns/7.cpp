// greed algorithm
#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int reverse(int x)
    {
        int n = 0;
        while (x != 0)
        {
            int d = (x % 10);
            if ((n > INT_MAX / 10) || (n < INT_MIN / 10))
            {
                return 0;
            }
            n = (n * 10) + d;

            x = x / 10;
        }

        return n;
    }
};