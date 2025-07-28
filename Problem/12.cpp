#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

class Solution
{
public:
    string intToRoman(int num)
    {
        string Ans;
        string RomanChar[100] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        int RomanNum[100] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        int index = 0;
        while (num > 0)
        {
            if (num - RomanNum[index] >= 0)
            {
                Ans += RomanChar[index];
                num -= RomanNum[index];
            }
            else
            {
                index++;
                continue;
            }
        }
        return Ans;
    };
};