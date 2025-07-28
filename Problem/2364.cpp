#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    long long countBadPairs(vector<int> &nums)
    {
        long long numbers = 0;
        for (int i = 0; i < nums.size() - 1; i++)
        {
            for (int j = i + 1; j < nums.size(); j++)
            {
                if (j - i != nums[j] - nums[i])
                    numbers++;
            }
        }
        return numbers;
    }
};