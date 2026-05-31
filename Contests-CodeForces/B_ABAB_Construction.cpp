#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    string s;
    cin >> n >> s;
    bool possible = true;
    if (n % 2 == 1 && s[0] == 'b') {
        possible = false;
    }
    if (possible) {
        int start = (n % 2 == 1) ? 1 : 0;
        for (int i = start; i + 1 < n; i += 2) {
            if (s[i] != '?' && s[i + 1] != '?' && s[i] == s[i + 1]) {
                possible = false;
                break;
            }
        }
    }
    cout << (possible ? "YES\n" : "NO\n");
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}