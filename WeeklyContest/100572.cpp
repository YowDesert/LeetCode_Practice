#include <bits/stdc++.h>

using namespace std;

// class Solution
// {
// public:
//     vector<int> assignElements(vector<int> &groups, vector<int> &elements)
//     {
//         for (int i = 0; i < groups.size(); i++)
//         {
//             double groupNumber = groups[i];
//             for (int j = 0; j < elements.size(); j++)
//             {

//                 double doubleNumber = elements[j];
//                 double isFloat = groups[i] / elements[j];
//                 double intPart;
//                 double fracPart = modf(isFloat, &intPart);
//                 if (fracPart == 0)
//                 {
//                     groups[i] = j;
//                     continue;
//                 }
//                 if (j == elements.size() - 1)
//                 {
//                     groups[i] = -1;
//                 }
//             }
//         }
//         return groups;
//     }
// };

class Solution
{
public:
    vector<int> assignElements(vector<int> &groups, vector<int> &elements)
    {
        vector<int> result(groups.size(), -1);

        for (int i = 0; i < groups.size(); i++)
        {
            for (int j = 0; j < elements.size(); j++)
            {
                if (fmod(groups[i], elements[j]) == 0)
                {
                    result[i] = j;
                    break;
                }
            }
        }
        return result;
    }
};