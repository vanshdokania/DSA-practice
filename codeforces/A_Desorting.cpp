#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main() {
    ll t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        vector<ll> arr(n);
        bool sorted = true;
        ll gap = INT_MAX;
        for (ll i = 0; i < n; i++) {
            cin >> arr[i];
            if (i != 0) {
                gap = min(gap, arr[i] - arr[i - 1]);
            }
            if (i != 0 && arr[i] < arr[i - 1]) {
                sorted = false;
            }
        }
        if (!sorted) {
            cout << 0 << '\n';
        } else {
            cout << gap / 2 + 1 << '\n';
        }
    }
    return 0;
}