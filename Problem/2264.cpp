#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    string largestGoodInteger(string num)
    {
        char bestAns = 0;
        for (int i = 0; i + 2 < num.size(); i++)
        {
            if (num[i] == num[i + 1] && num[i] == num[i + 2])
            {
                if (num[i] > bestAns)
                    bestAns = num[i];
            }
        }
        return bestAns ? string(3, bestAns) : "";
    }
};

int main()
{
    Solution sol;

    string num = "6777133339";
    cout << sol.largestGoodInteger(num) << endl;
    return 0;
}