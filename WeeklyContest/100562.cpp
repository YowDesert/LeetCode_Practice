// #include <bits/stdc++.h>

// using namespace std;

// class Solution
// {
// public:
//     vector<vector<int>> sortMatrix(vector<vector<int>> &grid)
//     {
//         int matrixSize = grid[0].size();
//         vector<int> NumberSort, upSort;
//         for (int i = 0; i < matrixSize; i++)
//         {
//             for (int j = 0; j < matrixSize - i; j++)
//             {
//                 NumberSort.push_back(grid[j - i][j + i]);
//             }
//             sort(NumberSort.begin(), NumberSort.end());
//             for (int j = 0; j < NumberSort.size(); j++)
//             {
//                 grid[j - i][i + j] = NumberSort[j];
//             }
//             NumberSort.clear();
//         }
//         return grid;
//     }
// };

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<vector<int>> sortMatrix(vector<vector<int>> &grid)
    {
        int n = grid.size();
        for (int i = 0; i < n; i++)
        {
            vector<int> NumberSort;
            int x = i, y = 0;
            while (x < n && y < n)
            {
                NumberSort.push_back(grid[x][y]);
                x++;
                y++;
            }

            sort(NumberSort.rbegin(), NumberSort.rend());

            x = i, y = 0;
            int index = 0;
            while (x < n && y < n)
            {
                grid[x][y] = NumberSort[index++];
                x++;
                y++;
            }
        }

        for (int j = 1; j < n; j++)
        {
            vector<int> NumberSort;
            int x = 0, y = j;
            while (x < n && y < n)
            {
                NumberSort.push_back(grid[x][y]);
                x++;
                y++;
            }

            sort(NumberSort.begin(), NumberSort.end());

            x = 0, y = j;
            int index = 0;
            while (x < n && y < n)
            {
                grid[x][y] = NumberSort[index++];
                x++;
                y++;
            }
        }
        return grid;
    }
};