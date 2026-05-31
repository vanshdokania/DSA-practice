#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        bool flag = false;
        for (int i = 1; i <= n; i++) {
            int x;
            cin >> x;
            if (x == 67) {
                flag = true;
            }
        }
        if (flag) cout << "YES\n";
        else cout << "NO\n";        
    }
    return 0;
}

