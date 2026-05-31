#include <bits/stdc++.h>
using namespace std;
#define ll long long int
static const ll MOD = 1000000007LL;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        ll c;
        string s;
        cin >> n >> c >> s;
        if (c == 1 || s.front() == '0' || s.back() == '0') {
            cout << -1 << '\n';
            continue;
        }
        ll waysMod = 1;
        ll waysC = 1 % c;
        bool invalid = false;
        for (int pos = 1; pos < n; pos++) {
            ll multiplier;
            if (s[pos - 1] == '1') {
                multiplier = 2;
            } else {
                if (pos == 1) {
                    invalid = true;
                    break;
                }
                multiplier = pos - 1;
            }
            waysMod = (waysMod * multiplier) % MOD;
            waysC = (waysC * multiplier) % c;
        }
        if (invalid || waysC == 0) {
            cout << -1 << '\n';
        } else {
            cout << waysMod << '\n';
        }
    }
    return 0;
}
