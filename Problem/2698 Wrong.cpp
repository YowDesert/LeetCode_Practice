#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int punishmentNumber(int n)
    {
        int Ans = 0;
        for (int i = 1; i <= n; i++)
        {
            int square, SepeSquare = 0;
            square = i * i;
            SepeSquareCalculate(to_string(square), i, 0);
            if (SepeSquare == i)
            {
                Ans += i * i;
            }
        }
        return Ans;
    }
    int SepeSquareCalculate(string substr, int target, int index)
    {
        }
};

// int main()
// {
//     Solution sol;
//     int n = 10;
//     cout << sol.punishmentNumber(n);
// }