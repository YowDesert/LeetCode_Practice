#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <stack>

using namespace std;

class Solution
{
public:
    string smallestNumber(string pattern)
    {
        int index = 0;
        string Ans;
        stack<char> NumStack;
        for (int i = 1; i <= pattern.size() + 1; i++)
        {
            NumStack.push('0' + i);
            if (pattern[index] == 'I' || i - 1 == pattern.size())
            {
                while (!NumStack.empty())
                {
                    Ans.push_back(NumStack.top());
                    NumStack.pop();
                }
            }
            index++;
        }
        return Ans;
    }
};

int main()
{
    Solution sol;
    cout << sol.smallestNumber("IIIDIDDD");
}