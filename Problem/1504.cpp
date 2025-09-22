#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;
class Solution
{
public:
    int numSubmat(vector<vector<int>> &mat)
    {
        int r = mat.size(), c = mat[0].size(), ans = 0;
        vector<int> h(c);
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
                h[j] = mat[i][j] ? h[j] + 1 : 0;
            vector<int> sum(c);
            stack<int> st;
            for (int j = 0; j < c; j++)
            {
                while (!st.empty() && h[st.top()] >= h[j])
                    st.pop();
                if (!st.empty())
                {
                    int p = st.top();
                    sum[j] = sum[p] + h[j] * (j - p);
                }
                else
                {
                    sum[j] = h[j] * (j + 1);
                }
                st.push(j);
                ans += sum[j];
            }
        }
        return ans;
    }
};
class Solution
{
public:
    int numSubmat(vector<vector<int>> &mat)
    {
        int m = mat.size();
        int n = mat[0].size();
        int counts = 0;

        // 直排
        //| i\j | 0 | 1 | 2 |
        //  | --- | - | - | - |
        //  | 0   | 1 | 0 | 1 |
        //  | 1   | 2 | 1 | 0 |
        //  | 2   | 3 | 2 | 0 |

        vector<vector<int>> height(m, vector<int>(n, 0));
        for (int j = 0; j < n; j++)
        {
            for (int i = 0; i < m; i++)
            {
                if (mat[i][j] == 1)
                {
                    height[i][j] = (i == 0 ? 1 : height[i - 1][j] + 1);
                }
            }
        }

        // 橫排加起來再加
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (height[i][j] == 0)
                    continue;
                int minHeight = height[i][j];
                // 往左擴展
                for (int k = j; k >= 0 && height[i][k] > 0; k--)
                {
                    minHeight = min(minHeight, height[i][k]);
                    counts += minHeight;
                }
            }
        }
        return counts;
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> mat = {{1, 0, 1}, {1, 1, 0}, {1, 1, 0}};
    cout << sol.numSubmat(mat) << endl;
    return 0;
}