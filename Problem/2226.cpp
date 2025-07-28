#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool cpm(int a, int b)
    {
        return a > b;
    }
    int maximumCandies(vector<int> &candies, long long k)
    {
        int sum = 0;
        for (int count : candies)
        {
            sum += count;
        }
        int maxcount = sum / k;
        for (int i = maxcount; i > 0; i--)
        {
            int totalpack = 0;
            for (int j = 0; j < candies.size(); j++)
            {
                totalpack += candies[j] / i;
            }
            if (totalpack >= k)
            {
                return i;
            }
        }
        return 0;
    }
};

int main()
{
    Solution sol;
    vector<int> candies = {5, 8, 6};
    long long k = 3;
    cout << sol.maximumCandies(candies, k);
}