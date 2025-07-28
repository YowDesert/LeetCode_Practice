#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int maxAbsoluteSum(vector<int> &nums)
{
    int max_sum = 0, min_sum = 0;
    int max_so_far = 0, min_so_far = 0;

    for (int num : nums)
    {
        max_so_far = max(num, max_so_far + num);
        min_so_far = min(num, min_so_far + num);

        max_sum = max(max_sum, max_so_far);
        min_sum = min(min_sum, min_so_far);
    }

    return max(abs(max_sum), abs(min_sum));
}