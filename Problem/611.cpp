#include <bits/stdc++.h>

using namespace std;
class Solution
{
public:
    int triangleNumber(vector<int> &nums)
    {
        sort(nums.begin(), nums.end()); // 先排序
        int n = nums.size();
        int count = 0;

        // 固定最大邊 k
        for (int k = n - 1; k >= 2; --k)
        {
            int i = 0, j = k - 1; // 兩個指標指向剩下的兩邊
            while (i < j)
            {
                if (nums[i] + nums[j] > nums[k])
                {
                    // nums[i] + nums[j] > nums[k]，代表所有 i..j-1 都符合
                    count += (j - i);
                    --j; // 換更小的第二大邊
                }
                else
                {
                    ++i; // 最小邊太小，往右移動
                }
            }
        }

        return count;
    }
};