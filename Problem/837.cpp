#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    double new21Game(int n, int k, int maxPts)
    {
        vector<vector<int>> dp;
        for (int i = 0; i < maxPts; i++)
        {
        }
    }
};

int main()
{
    Solution sol;
    //<= n 概率  ,k 達到或超過停下 , maxPts 最大點數
    int n, k, maxPts;
    n = 21, k = 17, maxPts = 10;
    cout << fixed << sol.new21Game(n, k, maxPts) << endl;
}