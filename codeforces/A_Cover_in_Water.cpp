#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        bool consThreeDots = false;
        for (int i = 0; i <= n - 2; i++) {
            if (s[i] == '.' && s[i + 1] == '.' && s[i + 2] == '.') {
                consThreeDots = true;
                break;
            }
        }
        if (consThreeDots) {
            cout << "2" << '\n';
            continue;
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '.') ans++;
        }
        cout << ans << '\n';
    }
    return 0;
}