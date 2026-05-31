#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, s, x;
        cin >> n >> s >> x;
        int a = 0;
        for (int i = 0; i < n; i++) {
            int b;
            cin >> b;
            a += b;
        }
        if (a > s) {
            cout << "NO\n";
            continue;
        }
        if ((s - a) % x == 0) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}