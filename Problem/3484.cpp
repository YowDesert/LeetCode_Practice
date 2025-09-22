// #include <bits/stdc++.h>

// using namespace std;

// class Spreadsheet
// {
// public:
//     vector<vector<int>> AlphaTable;
//     Spreadsheet(int rows)
//     {
//         AlphaTable.assign(rows, vector<int>(26, 0));
//     }

//     void setCell(string cell, int value)
//     {
//         int rows = cell[0] - 'A';
//         int columns = cell[1] - '0';
//         AlphaTable[rows][columns] = value;
//     }

//     void resetCell(string cell)
//     {
//         int rows = cell[0] - 'A';
//         int columns = cell[1] - '0';
//         AlphaTable[rows][columns] = 0;
//     }

//     int getValue(string formula)
//     {
//         string stra;
//         int a;
//         for (int i = 0; i < formula.size(); i++)
//         {
//             if (formula[i] == '=')
//             {
//                 continue;
//             }
//             if (formula[i] == '+')
//             {
//                 a = stoi(stra);
//                 stra.clear();
//             }
//             stra.push_back(formula[i]);
//         }

//         return a - stoi(stra);
//     }
// };

// /**
//  * Your Spreadsheet object will be instantiated and called as such:
//  * Spreadsheet* obj = new Spreadsheet(rows);
//  * obj->setCell(cell,value);
//  * obj->resetCell(cell);
//  * int param_3 = obj->getValue(formula);
//  */

#include <bits/stdc++.h>
using namespace std;

class Spreadsheet
{
public:
    vector<vector<int>> AlphaTable;
    Spreadsheet(int rows)
    {
        AlphaTable.assign(rows, vector<int>(26, 0));
    }

    void setCell(string cell, int value)
    {
        int col = cell[0] - 'A';
        int row = stoi(cell.substr(1)) - 1;
        AlphaTable[row][col] = value;
    }

    void resetCell(string cell)
    {
        int col = cell[0] - 'A';
        int row = stoi(cell.substr(1)) - 1;
        AlphaTable[row][col] = 0;
    }

    int getValue(string formula)
    {
        // 去掉 '='
        formula = formula.substr(1);
        // 找 '+'
        int plusPos = formula.find('+');
        string left = formula.substr(0, plusPos);
        string right = formula.substr(plusPos + 1);

        auto parseTerm = [&](string term) -> int
        {
            if (isalpha(term[0]))
            { // 是儲存格
                int col = term[0] - 'A';
                int row = stoi(term.substr(1)) - 1;
                return AlphaTable[row][col];
            }
            return stoi(term); // 是數字
        };

        return parseTerm(left) + parseTerm(right);
    }
};
