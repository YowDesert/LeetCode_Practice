#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

class Solution
{
public:
    string findDifferentBinaryString(vector<string> &nums)
    {
        int StringSize = nums[0].size();
        map<int, string> AllStringNumber;

        for (int i = 0; i < (int)nums.size(); i++)
        {
            int sum = 0;
            for (int j = 0; j < StringSize; j++)
            {
                sum = sum * 2 + (nums[i][j] - '0');
            }
            AllStringNumber[sum] = nums[i];
        }

        for (int i = 0; i < (1 << StringSize); i++)
        {
            if (AllStringNumber.count(i) == 0)
            {
                string Ans;
                int temp = i;

                while (temp > 0)
                {
                    Ans.push_back((temp % 2) ? '1' : '0');
                    temp /= 2;
                }
                while ((int)Ans.size() < StringSize)
                {
                    Ans.push_back('0');
                }
                reverse(Ans.begin(), Ans.end());

                return Ans;
            }
        }
        return "";
    }
};

int main()
{
    vector<string> nums = {"111", "011", "001"};
    Solution sol;
    cout << sol.findDifferentBinaryString(nums) << endl;
    return 0;
}
