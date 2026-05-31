#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        ll p, q;
        cin >> p >> q;
        ll D = q - p;
        if (3 * p >= 2 * q && D > 0) {
            cout << "Bob\n";
        } else {
            cout << "Alice\n";
        }
    }
    return 0;
}
