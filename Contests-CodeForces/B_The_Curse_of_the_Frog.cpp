#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        ll x;
        cin >> n >> x;
        ll freeReach = 0;
        ll maxGain = LLONG_MIN;
        for (int i = 0; i < n; i++) {
            ll a, b, c;
            cin >> a >> b >> c;
            freeReach += a * (b - 1);
            maxGain = max(maxGain, a * b - c);
        }
        if (freeReach >= x) {
            cout << 0 << '\n';
            continue;
        }
        if (maxGain <= 0) {
            cout << -1 << '\n';
            continue;
        }
        ll diff = x - freeReach;
        ll ans = (diff + maxGain - 1) / maxGain;
        cout << ans << '\n';
    }
    return 0;
}