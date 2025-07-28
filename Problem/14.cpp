#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    string longestCommonPrefix(vector<string> &strs)
    {
        int VecSize = strs.size();
        int StringSize = strs[0].size();

        string SameChar = strs[0];

        for (int i = 0; i < VecSize; i++)
        {
            for (int j = 0; j < StringSize; j++)
            {
                if (SameChar[j] != strs[i][j])
                {
                    SameChar.erase(j);
                }
            }
        }
        return SameChar;
    }
};

int main()
{
    Solution sol;
    vector<string> strs = {"flower", "flow", "flight"};
    cout << sol.longestCommonPrefix(strs);
}