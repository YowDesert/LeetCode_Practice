#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int maxAbsoluteSum(vector<int> &nums)
    {
        int MaxFarNum = 0, MinFarNum = 0;
        int theMaxNum = 0;
        int theSmallNum = 0;
        for (int num : nums)
        {
            MaxFarNum = max(num, num + MaxFarNum);
            MinFarNum = min(num, num + MinFarNum);

            theMaxNum = max(MaxFarNum, theMaxNum);
            theSmallNum = min(MinFarNum, theSmallNum);
        }
        return max(abs(theMaxNum), abs(theSmallNum));
    }
};