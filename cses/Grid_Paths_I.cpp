#include <bits/stdc++.h>
using namespace std;
#define ll long long int

const int MOD = 1e9 + 7;

// vector<vector<ll>> dp;

// ll f(vector<string>& grid, ll n, ll cr, ll cc) {
//     if (grid[cr][cc] == '*') return 0;
//     if (cc == n - 1 && cr == n - 1) return 1;
//     if (dp[cr][cc] != -1) return dp[cr][cc];
//     ll right = 0;
//     if (cc + 1 < n && grid[cr][cc + 1] == '.') right = (f(grid, n, cr, cc + 1)) % MOD;
//     ll down = 0;
//     if (cr + 1 < n && grid[cr + 1][cc] == '.') down = (f(grid, n, cr + 1, cc)) % MOD;
//     return dp[cr][cc] = (right + down) % MOD;
// }

ll fbu(vector<string>& grid, ll n) {
    vector<vector<int>> dp(n, vector<int>(n, 0));
    if (grid[n - 1][n - 1] == '.') dp[n - 1][n - 1] = 1;
    for (ll i = n - 1; i >= 0; i--) {
        for (ll j = n - 1; j >= 0; j--) {
            if (grid[i][j] == '*') {
                dp[i][j] = 0;
                continue;
            }
            if (i == n - 1 && j == n - 1) continue;
            ll right = 0;
            if (j + 1 < n && grid[i][j + 1] == '.') right = (dp[i][j + 1]) % MOD;
            ll down = 0;
            if (i + 1 < n && grid[i + 1][j] == '.') down = (dp[i + 1][j]) % MOD;
            dp[i][j] = (down + right) % MOD;
        }
    }
    return (dp[0][0]) % MOD;
}

int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);
    // #ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // #endif
    ll n;
    cin >> n;
    vector<string> grid(n);
    for (ll i = 0; i < n; i++) cin >> grid[i];
    // dp.assign(n + 1, vector<ll>(n + 1, -1));
    cout << fbu(grid, n);
    return 0;
}