#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        vector<long long> st;       // 用 long long 防止中途乘法溢位
        st.reserve(nums.size());

        auto gcdll = [](long long a, long long b){
            return std::gcd(a, b);
        };
        auto lcmll = [&](long long a, long long b){
            long long g = gcdll(a, b);
            // 先除後乘，減少溢位風險
            return (a / g) * b;
        };

        for (int v : nums) {
            long long x = v;
            // 只要頂端與 x 非互質，就不斷融合
            while (!st.empty()) {
                long long g = gcdll(st.back(), x);
                if (g == 1) break;
                x = lcmll(st.back(), x);
                st.pop_back();
            }
            st.push_back(x);
        }

        // 題目保證最終值 <= 1e8，可安全轉回 int
        vector<int> ans;
        ans.reserve(st.size());
        for (auto val : st) ans.push_back((int)val);
        return ans;
    }
};
