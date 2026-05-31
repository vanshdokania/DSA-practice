#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main() {
    ll t;
    cin >> t;
    while (t--) {
        ll n, k;
        cin >> n >> k;
        if (n % 2 == 0 || (n - k) % 2 == 0) cout << "YES" << '\n';
        else cout << "NO" << '\n';
    }
    return 0;
}