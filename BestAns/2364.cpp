// beats 100%
// j−i !=nums[j]−nums[i]
// nums[j]−j!=nums[i]−i
#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    long long countBadPairs(vector<int> &nums)
    {
        unordered_map<int, int> freq;
        long long goodPairs = 0, n = nums.size();

        for (int i = 0; i < n; i++)
        {
            int key = nums[i] - i;
            goodPairs += freq[key];
            freq[key]++;
        }

        return (n * (n - 1)) / 2 - goodPairs;
    }
};