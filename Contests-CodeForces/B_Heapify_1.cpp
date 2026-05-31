#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        bool flag = true;
        for (int i = 1; i <= n; i++) {
            int num;
            cin >> num;
            int a = i;
            int b = num;
            while (a % 2 == 0) {
                a /= 2;
            }
            while (b % 2 == 0) {
                b /= 2;
            }
            if (a != b) flag = false;
        }
        if (flag) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}
