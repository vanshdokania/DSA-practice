#include <bits/stdc++.h>
using namespace std;

// vector<vector<int>> dp;

// int f(int n, int x, vector<int>& weight, vector<int>& profit, int idx) {
//     if (idx == n) return 0;
//     if (dp[idx][x] != -1) return dp[idx][x];
//     int skip = f(n, x, weight, profit, idx + 1);
//     int take = 0;
//     if (weight[idx] <= x) {
//         take = profit[idx] + f(n, x - weight[idx], weight, profit, idx + 1);
//     }
//     return dp[idx][x] = max(skip, take);
// }


int fbu(int n, int x, vector<int>& weight, vector<int>& profit) {
    vector<vector<int>> dp(n + 1, vector<int>(x + 1, 0));
    for (int i = 0; i <= x; i++) dp[n][i] = 0;
    for (int i = n - 1; i >= 0; i--) {
        for (int j = 0; j <= x; j++) {
            int skip = dp[i + 1][j];
            int take = 0;
            if (weight[i] <= j) {
                take = profit[i] + dp[i + 1][j - weight[i]];
            }
            dp[i][j] = max(skip, take);
        }   
    }
    return dp[0][x];
}

int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);
    // #ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // #endif
    int n, x;
    cin >> n >> x;
    vector<int> weight(n);
    for (int i = 0; i < n; i++) cin >> weight[i];
    vector<int> profit(n);
    for (int i = 0; i < n; i++) cin >> profit[i];
    // dp.assign(n + 1, vector<int>(x + 1, -1));
    cout << fbu(n, x, weight, profit);
    return 0;
}