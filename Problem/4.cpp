#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        for (int i = 0; i < nums2.size(); i++)
        {
            nums1.push_back(nums2[i]);
        }
        sort(nums1.begin(), nums1.end());
        float med = nums1.size() / 2.0;
        return (med - floor(med) != 0)
                   ? nums1[med]
                   : double((nums1[med] + nums1[med + 1]) / 2.0);
    }
};