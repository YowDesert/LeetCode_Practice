#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int maximumDifference(vector<int> &nums)
    {
        int MaxNum = -1;
        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = i; j < nums.size(); j++)
            {
                if (nums[i] < nums[j] && nums[j] - nums[i] > MaxNum)
                {
                    MaxNum = nums[j] - nums[i];
                }
            }
        }
        return MaxNum;
    }
};

class Solution
{
public:
    int maximumDifference(vector<int> &nums)
    {
        int MaxNum = -1;
        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = i; j < nums.size(); j++)
            {
                if (nums[i] < nums[j] && nums[j] - nums[i] > MaxNum)
                {
                    MaxNum = nums[j] - nums[i];
                }
            }
        }
        return MaxNum;
    }

    int maximumDifference(vector<int> &nums)
    {
        int MaxDiff = -1;
        int minValue = nums[0];
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] > minValue)
            {

                MaxDiff = max(nums[i] - minValue, MaxDiff);
            }
            else
                minValue = nums[i];
        }
        return MaxDiff;
    }
};

int main()
{
    Solution Sol;
    vector<int> nums = {{7}, {1}, {5}, {4}};

    cout << Sol.maximumDifference(nums);
}