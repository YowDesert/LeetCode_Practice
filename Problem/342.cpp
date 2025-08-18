#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    bool isPowerOfFour(int n)
    {
        return n > 0 && (n & (n - 1)) && (n & 0x55555555);
    }
};
// class Solution
// {
// public:
//     bool isPowerOfFour(int n)
//     {
//         if (n == 0)
//         {
//             return false;
//         }
//         while (n != 1)
//         {
//             if (n % 4 != 0)
//             {
//                 return false;
//             }
//             else
//             {
//                 n /= 4;
//             }
//         }
//         return true;
//     }
// };

int main()
{
    Solution sol;
    int n;
    cout << sol.isPowerOfFour(n) << endl;
}