#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

class Solution
{
public:
    int minPairSum(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int i = 0, j = (int)nums.size() - 1;
        int ans = 0;

        while (i < j)
        {
            ans = max(ans, nums[i] + nums[j]);
            ++i;
            --j;
        }
        return ans;
    }
};

int main()
{
    Solution sol;
    vector<int> nums;
    nums = {3, 5, 4, 2, 4, 6};
    cout << sol.minPairSum(nums);
    return 0;
}
