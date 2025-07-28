#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int countMaxOrSubsets(vector<int> &nums)
    {
        int n = nums.size();
        int maxOr = 0;
        int count = 0;

        // 枚舉所有非空子集合
        for (int mask = 1; mask < (1 << n); ++mask)
        {
            int currentOr = 0;
            for (int i = 0; i < n; ++i)
            {
                if (mask & (1 << i))
                {
                    currentOr |= nums[i];
                }
            }

            if (currentOr > maxOr)
            {
                maxOr = currentOr;
                count = 1;
            }
            else if (currentOr == maxOr)
            {
                count++;
            }
        }

        return count;
    }
};

int main()
{
    Solution solution;
    vector<int> nums = {3, 1, 5, 7, 9};
    int result = solution.countMaxOrSubsets(nums);
    cout << "Number of maximum bitwise-OR subsets: " << result << endl;
    return 0;
}
