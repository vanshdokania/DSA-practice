#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int fbu(int sum, vector<int>& coins) {
    vector<int> dp(sum + 1, INT_MAX);
    dp[0] = 0;
    for (int i = 1; i <= sum; i++) {
        for (auto coin : coins) {
            if (i - coin >= 0 && dp[i - coin] != INT_MAX) {
                dp[i] = min(dp[i], 1 + dp[i - coin]);
            }
        }
    }
    if (dp[sum] == INT_MAX) return -1;
    return dp[sum];
}
int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);
    // #ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // #endif
    int n, sum;
    cin >> n >> sum;
    vector<int> coins(n);
    for (int i = 0; i < n; i++) cin >> coins[i];
    cout << fbu(sum, coins);
    return 0;
}