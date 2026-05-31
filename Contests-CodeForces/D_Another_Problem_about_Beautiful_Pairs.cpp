#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    ll ans = 0;
    int limit = sqrt(n);
    for (int i = 1; i <= n; i++) {
        if (a[i] > limit) {
            for (ll k = 1; ; k++) {
                ll j = i + (ll)a[i] * k;
                if (j > n) break;
                if (a[j] == k) ans++;
            }
        }
    }
    for (int k = 1; k <= limit; k++) {
        for (int j = 1; j <= n; j++) {
            ll d = (ll)k * a[j];
            if (d < j && a[j - d] == k) {
                ans++;
            }
        }
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
