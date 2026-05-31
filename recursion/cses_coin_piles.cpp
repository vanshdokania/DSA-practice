#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    ll n;
    cin >> n;
    for (ll i = 0; i < n; i++) {
        ll a, b;
        cin >> a >> b;
        if (max(a, b) <= 2 * min(a, b) && (a + b) % 3 == 0) {
            cout << "YES" << "\n";
        } else cout << "NO" << "\n";
    }
    return 0;
}