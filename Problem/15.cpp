#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        int n = nums.size();

        for (int i = 0; i < n - 2; i++)
        {
            if (i > 0 && nums[i] == nums[i - 1])
                continue; // skip duplicate i
            if (nums[i] > 0)
                break; // 因為已排序，i>0 後面都 >0 不可能湊 0

            int j = i + 1, k = n - 1;
            while (j < k)
            {
                long long sum = 1LL * nums[i] + nums[j] + nums[k];

                if (sum == 0)
                {
                    ans.push_back({nums[i], nums[j], nums[k]});
                    j++;
                    k--;

                    while (j < k && nums[j] == nums[j - 1])
                        j++; // skip dup j
                    while (j < k && nums[k] == nums[k + 1])
                        k--; // skip dup k
                }
                else if (sum < 0)
                {
                    j++;
                }
                else
                {
                    k--;
                }
            }
        }
        return ans;
    }
};
