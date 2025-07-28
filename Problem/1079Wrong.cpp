#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    int numTilePossibilities(string tiles)
    {
        unordered_map<string, int> TypeStr;
        unordered_map<char, int> CharNum;
        for (auto c : tiles)
        {
            CharNum[c]++;
        }
    }
};