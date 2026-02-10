#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int threeSumClosest(vector<int> &nums, int target)
    {
        sort(nums.begin(), nums.end());
        int n = nums.size();

        long long bestSum = (long long)nums[0] + nums[1] + nums[2];
        long long bestDiff = llabs((long long)target - bestSum);

        for (int i = 0; i < n - 2; ++i)
        {
            int j = i + 1, k = n - 1;
            while (j < k)
            {
                long long sum = (long long)nums[i] + nums[j] + nums[k];
                long long diff = llabs((long long)target - sum);

                if (diff < bestDiff)
                {
                    bestDiff = diff;
                    bestSum = sum;
                }

                if (sum == target)
                    return target;
                else if (sum < target)
                    ++j;
                else
                    --k;
            }
        }
        return (int)bestSum;
    }
};
