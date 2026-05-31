#include <bits/stdc++.h>
using namespace std;
#define ll long long int

const int MOD = 1e9 + 7;

vector<vector<int>> dp;

ll f(ll sum, ll idx, ll n) {
    if (sum == 0) return 1;
    if (idx == n || sum < 0) return 0;
    if (dp[idx][sum] != -1) return dp[idx][sum];
    ll skip = f(sum, idx + 1, n);
    ll take = f(sum - idx, idx + 1, n);
    return dp[idx][sum] = (skip + take) % MOD;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    ll n;
    cin >> n;
    ll sum = (n * (n + 1)) / 2;
    if (sum % 2 != 0) {
        cout << "0";
        return 0;
    }
    sum = sum / 2;
    dp.resize(n + 1, vector<int>(sum + 1, -1));
    cout << f(sum, 1, n);
    return 0;
}