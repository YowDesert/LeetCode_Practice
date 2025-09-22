#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    string longestCommonPrefix(vector<string> &strs)
    {
        if (strs.empty())
            return "";

        string ans;
        int index = 0;

        while (true)
        {
            char c;
            if (index < strs[0].size())
                c = strs[0][index];
            else
                break;

            for (int i = 1; i < strs.size(); i++)
            {
                if (index >= strs[i].size() || strs[i][index] != c)
                    return ans;
            }

            ans.push_back(c);
            index++;
        }

        return ans;
    }
};

int main()
{
    Solution sol;
    vector<string> strs = {"flower", "flow", "flight"};
    cout << sol.longestCommonPrefix(strs);
}