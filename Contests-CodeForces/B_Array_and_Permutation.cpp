#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> idxArr(n + 1);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        idxArr[x] = i;
    }
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int lastPos = -1;
    for (int i = 0; i < n; i++) {
        if (i > 0 && a[i] == a[i - 1]) continue;
        if (idxArr[a[i]] < lastPos) {
            cout << "NO\n";
            return;
        }
        lastPos = idxArr[a[i]];
    }
    cout << "YES\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
