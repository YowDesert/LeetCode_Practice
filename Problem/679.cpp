#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

class Solution
{
public:
    bool judgePoint24(vector<int> &cards)
    {
        vector<double> nums;
        for (int c : cards)
            nums.push_back((double)c);
        return dfs(nums);
    }

    bool dfs(vector<double> &nums)
    {
        if (nums.size() == 1)
        {
            return fabs(nums[0] - 24) < 1e-6;
        }

        int n = nums.size();
        for (int i = 0; i < nums.size() - 1; i++)
        {
            for (int j = i + 1; j < nums.size(); j++)
            {
                vector<double> next;
                for (int k = 0; k < n; k++)
                {
                    if (k != i && k != j)
                        next.push_back(nums[k]);
                }

                for (double res : compute(nums[i], nums[j]))
                {
                    next.push_back(res);
                    if (dfs(next))
                        return true;
                    next.pop_back();
                }
            }
        }
        return false;
    }

    vector<double> compute(double a, double b)
    {
        vector<double> results;
        results.push_back(a + b);
        results.push_back(a - b);
        results.push_back(b - a);
        results.push_back(a * b);
        if (fabs(a) > 1e-6)
            results.push_back(b / a);
        if (fabs(b) > 1e-6)
            results.push_back(a / b);

        return results;
    }
};

int main()
{
    Solution sol;
    vector<int> card = {4, 1, 8, 7};
    cout << sol.judgePoint24(card);
}