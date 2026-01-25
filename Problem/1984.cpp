#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int minimumDifference(vector<int> &nums, int k)
    {
        if (k == 1)
        {
            return 0;
        }

        sort(nums.begin(), nums.end());
        int min = INT_MAX;
        int temp;
        for (int i = 0; i <= nums.size() - k; i++)
        {
            temp = nums[i + k - 1] - nums[i];

            if (temp < min)
            {
                min = temp;
            }
        }

        return min;
    }
};

int main()
{
    Solution sol;

    vector<int> nums;
    int k;

    cout << sol.minimumDifference(nums, k);
}