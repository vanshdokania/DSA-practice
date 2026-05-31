#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main() {
    ll t;
    cin >> t;
    while (t--) {
        ll a, b, n;
        cin >> a >> b >> n;
        vector<ll> arr(n);
        for (ll i = 0; i < n; i++) cin >> arr[i];
        ll sum = 0;
        for (ll i = 0; i < n; i++) {
            sum += min(arr[i], a - 1);
        }
        sum += b;
        cout << sum << '\n'; 
    }
    return 0;
}