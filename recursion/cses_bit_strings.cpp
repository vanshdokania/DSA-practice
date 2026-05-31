#include <bits/stdc++.h>
using namespace std;
#define ll long long int
const ll mod = 1000000007;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    ll n;
    cin >> n;
    ll ans = 1;
    for (ll i = 1; i <= n; i++) {
        ans = (ans * 2) % mod;
    }
    cout << ans;
    return 0;
}