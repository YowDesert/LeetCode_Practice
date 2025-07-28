#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    long long maxWeight(vector<int> &pizzas)
    {

        sort(pizzas.begin(), pizzas.end(), greater<int>());
        int n = pizzas.size();
        long maxW = 0;

        for (int i = 0; i < n / 4; i++)
        {

            int W = pizzas[i * 4];
            int X = pizzas[i * 4 + 1];
            int Y = pizzas[i * 4 + 2];
            int Z = pizzas[i * 4 + 3];

            if (i % 2 == 0)
                maxW += W;

            else
                maxW += X;
        }

        return maxW;
    }
};
