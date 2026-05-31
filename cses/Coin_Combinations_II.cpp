#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int f(vector<int>& coins, int sum, int currSum, int idx) {
    vector<vector<int>> dp;
    if (currSum == sum) return 1;
    if (idx == coins.size()) return 0;
    if (dp[idx][currSum] != -1) return dp[idx][currSum];
    int skip = (f(coins, sum, currSum, idx + 1)) % MOD;
    int take = 0;
    if (currSum + coins[idx] <= sum) {
        take = (f(coins, sum, currSum + coins[idx], idx)) % MOD;
    }
    return dp[idx][currSum] = (skip + take) % MOD;
} 

int fbu(vector<int>& coins, int sum) {
    vector<vector<int>> dp(coins.size() + 1, vector<int>(sum + 1, 0));
    for (int i = 0; i <= coins.size(); i++) dp[i][0] = 1;
    for (int i = coins.size() - 1; i >= 0; i--) {
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
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int n, sum;
    cin >> n >> sum;
    vector<int> coins(n);
    for (int i = 0; i < n; i++) cin >> coins[i];
    cout << fbu(coins, sum);
    return 0;
}