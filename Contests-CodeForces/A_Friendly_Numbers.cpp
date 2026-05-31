#include <bits/stdc++.h>
using namespace std;
#define ll long long int
ll sum_of_digits(ll y) {
    ll s = 0;
    while (y) {
        s += y % 10;
        y /= 10;
    }
    return s;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        ll x;
        cin >> x;
        int ans = 0;
        for (ll y = x; y <= x + 90; y++) {
            if (y - sum_of_digits(y) == x) ans++;
        }
        cout << ans << '\n';
    }
    return 0;
}
