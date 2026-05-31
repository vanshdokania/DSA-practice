#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int fbu(vector<int>& coins, int sum, int n) {
    vector<vector<int>> dp(n + 1, vector<int>(sum + 1, 0));
    for (int i = 0; i <= n; i++) dp[i][0] = 1;
    for (int i = n - 1; i >= 0; i--) {
        for (int j = 1; j <= sum; j++) {
            int skip = dp[i + 1][j];
            int take = 0;
            if (j - coins[i] >= 0) {
                take = dp[i][j - coins[i]];
            }
            dp[i][j] = (skip + take) % MOD;
        }
    }
    return dp[0][sum];
}

int main() {
    int n, sum;
    cin >> n >> sum;
    vector<int> coins(n);
    for (int i = 0; i < n; i++) cin >> coins[i];
    cout << fbu(coins, sum, n);
    return 0;
}