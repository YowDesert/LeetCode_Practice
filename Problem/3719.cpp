#include <bits/stdc++.h>

using namespace std;

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int longestBalanced(vector<int> &nums)
    {
        int n = nums.size();
        int ans = 0;

        for (int i = 0; i < n; ++i)
        {
            unordered_set<int> seen;
            int ce = 0, co = 0; // distinct even / distinct odd

            for (int j = i; j < n; ++j)
            {
                if (!seen.count(nums[j]))
                {
                    seen.insert(nums[j]);
                    if (nums[j] % 2 == 0)
                        ce++;
                    else
                        co++;
                }
                if (ce == co)
                    ans = max(ans, j - i + 1);
            }
        }
        return ans;
    }
};
