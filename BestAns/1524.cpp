#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int numOfSubarrays(vector<int> &arr)
    {
        const int MOD = 1'000'000'007;           // 防止溢出
        long long odd_count = 0, even_count = 1; // 初始 even_count = 1，因為前綴和 0 是偶數
        long long prefix_sum = 0, result = 0;

        for (int a : arr)
        {
            prefix_sum += a; // 計算前綴和

            if (prefix_sum % 2 == 0)
            {                        // 當前前綴和是偶數
                result += odd_count; // 之前的 odd_count 可以與這個偶數前綴和形成奇數子陣列
                even_count++;        // 當前前綴和是偶數，更新 even_count
            }
            else
            {                         // 當前前綴和是奇數
                result += even_count; // 之前的 even_count 可以與這個奇數前綴和形成奇數子陣列
                odd_count++;          // 當前前綴和是奇數，更新 odd_count
            }

            result %= MOD; // 防止溢出
        }

        return result;
    }
};
