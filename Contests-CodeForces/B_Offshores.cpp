#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        ll x, y;
        cin >> n >> x >> y;
        vector<ll> arr(n);
        for (auto &val : arr) cin >> val;
        ll tb = 0;
        for (ll val : arr) tb += (val / x) * y;
        ll ans = 0;
        for (ll val : arr) {
            ll current = val + tb - (val / x) * y;
            ans = max(ans, current);
        }
        cout << ans << '\n';
    }
    return 0;
}
