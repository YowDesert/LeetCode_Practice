#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        const int MOD = 1e9 + 7;
        vector<long long> dp(n + 1, 0);
        dp[1] = 1;  // 第 1 天一個人知道

        for (int i = 1; i <= n; i++) {
            for (int j = i + delay; j < i + forget && j <= n; j++) {
                dp[j] = (dp[j] + dp[i]) % MOD;
            }
        }

        // 統計最後還記得的人
        long long ans = 0;
        for (int i = n - forget + 1; i <= n; i++) {
            if (i >= 1) ans = (ans + dp[i]) % MOD;
        }
        return ans;
    }
};


int main(){
    Solution sol;
    int n,delay,forget;
    n = 6, delay = 2, forget = 4;
    cout << sol.peopleAwareOfSecret(n,delay,forget);
}