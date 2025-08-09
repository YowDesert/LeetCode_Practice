#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
class Solution
{
public:
    bool isPowerOfTwo(int n)
    {
        if (n == 0 || n < 0)
        {
            return false;
        }
        while (n > 1)
        {
            if (n % 2 != 0)
            {
                return false;
            }
            else
            {
                n /= 2;
            }
        }
        return true;
    }
};

int main()
{
    Solution sol;
    int n = 16;
    cout << sol.isPowerOfTwo(n) << endl;
    return 0;
}