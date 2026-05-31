#include <bits/stdc++.h>
using namespace std;
#define ll long long int
vector<ll> dp;
const ll MOD = 1e9 + 7;
ll f(ll sum, ll currSum) {
    if (sum == currSum) return 1;
    if (dp[currSum] != -1) return dp[currSum];
    ll ways = 0;
    for (int i = 1; i <= 6; i++) {
        if (i + currSum <= sum) {
            ways = (ways + f(sum, currSum + i)) % MOD;
        }
    }
    return dp[currSum] = (ways) % MOD;
}
int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);
    // #ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // #endif
    dp.assign(1000001, -1);
    ll sum;
    cin >> sum;
    cout << f(sum, 0);
    return 0;
}