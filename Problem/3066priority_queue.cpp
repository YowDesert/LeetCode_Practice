#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <queue>
// priority_queue<T, vector<T>, greater<T> > pq;  改成由小排到大
using namespace std;

class Solution
{
public:
    int minOperations(vector<int> &nums, int k)
    {
        priority_queue<long long, vector<long long>, greater<long long>> pq(nums.begin(), nums.end());
        int times = 0;

        while (pq.top() < k)
        {
            long long smallest = pq.top();
            pq.pop();
            long long second_smallest = pq.top();
            pq.pop();

            long long sumNum = smallest * 2 + second_smallest;
            pq.push(sumNum);

            times++;
        }
        return times;
    }
};

// int main()
// {
//     vector<int> nums = {999999999, 999999999, 999999999};
//     int k = 1000000000;

//     Solution solution;
//     int result = solution.minOperations(nums, k);
//     cout << "需要的最少操作次數: " << result << endl;

//     return 0;
// }