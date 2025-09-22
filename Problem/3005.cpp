#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int maxFrequencyElements(vector<int> &nums)
    {
        int maxFreq = 0;
        vector<int> Freq(101, 0);
        for (int i = 0; i < nums.size(); i++)
        {
            Freq[nums[i]]++;
            maxFreq = max(maxFreq, Freq[nums[i]]);
        }

        int result = 0;
        for (int f : Freq)
        {
            if (f == maxFreq)
                result += f;
        }

        return result;
    }
};