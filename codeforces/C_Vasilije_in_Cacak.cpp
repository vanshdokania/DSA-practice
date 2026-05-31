#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int main() {
    ll t;
    cin >> t;
    while (t--) {
        ll n, k, x;
        cin >> n >> k >> x;
        ll largest = k * (2*n - k + 1) / 2;
        ll smallest = smallest = k * (k + 1) / 2;
        if (largest >= x && smallest <= x) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}