#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<ll> a(n), b(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < n; i++) cin >> b[i];
        sort(a.begin(), a.end(), greater<ll>());
        vector<ll> pref(n);
        pref[0] = b[0];
        for (int i = 1; i < n; i++) pref[i] = pref[i - 1] + b[i];
        ll ans = 0;
        for (int k = 1; k <= n; k++) {
            ll need = pref[k - 1];
            if (need > n) break;
            ll x = a[need - 1];
            ans = max(ans, x * k);
        }
        cout << ans << '\n';
    }
    return 0;
}
