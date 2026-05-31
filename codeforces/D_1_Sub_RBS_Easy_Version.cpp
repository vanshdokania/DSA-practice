#include <bits/stdc++.h>
using namespace std;


int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        int x, ans;
        x = 0;
        ans = -1;
        for (int i = n - 1; i >= 0; i--) {
            if (s[i] == '(') {
                x++;
            } else {
                if (x >= 2) {
                    ans = n - 2;
                    break;
                }
            }
        }
        cout << ans << "\n";
    }
    return 0;
}