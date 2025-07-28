// #include <bits/stdc++.h>
// using namespace std;

// class Solution
// {
// public:
//     int maxArea(vector<int> &height)
//     {
//         int firstNum, secondNum, maxNum = 0;
//         for (int i = 0; i < height.size(); i++)
//         {
//             for (int j = i; j < height.size(); j++)
//             {
//                 if ((j - i) * min(height[i], height[j]) > maxNum)
//                 {
//                     maxNum = (j - i) * min(height[i], height[j]);
//                 }
//             }
//         }
//         return maxNum;
//     }
// };
#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int maxArea(vector<int> &height)
    {
        int left, right, theBiggest = -1, Volume;
        left = 0;
        right = height.size() - 1;
        while (left != right)
        {
            Volume = (right - left) * min(height[right], height[left]);
            if (theBiggest < Volume)
                theBiggest = Volume;
            if (height[right] == height[left])
                left++;
            else
            {
                height[right] > height[left] ? left++ : right--;
            }
        }
        return theBiggest;
    }
};