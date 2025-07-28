// binary search
#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int maximumCandies(vector<int> &candies, long long k)
    {
        int minDistribute = 1, maxDistribute = *max(candies.begin(), candies.end());
        int bestAns = 0;

        while (minDistribute <= maxDistribute)
        {
            long long midDistribute = minDistribute + (maxDistribute - minDistribute) / 2;
            long long children_count = 0;

            for (int pile : candies)
            {
                children_count += pile / midDistribute;
            }
            if (children_count >= k)
            {
                bestAns = midDistribute;
                minDistribute = midDistribute + 1;
            }
            else
            {
                maxDistribute = midDistribute - 1;
            }
        }
        return bestAns;
    }
};

// class Solution {
//     public:
//         int maximumCandies(vector<int>& candies, long long k) {
//             long long left = 1, right = *max_element(candies.begin(), candies.end());
//             int result = 0;

//             while (left <= right) {
//                 long long mid = left + (right - left) / 2;
//                 long long children_count = 0;

//                 for (int pile : candies) {
//                     children_count += pile / mid;
//                 }

//                 if (children_count >= k) {
//                     result = mid;
//                     left = mid + 1;
//                 } else {
//                     right = mid - 1;
//                 }
//             }

//             return result;
//         }
//     };