#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int s, k, m;
        cin >> s >> k >> m;
        int f = m / k;
        int r = m % k;
        int ans = -1;
        if (f == 0) {
            ans = s - r;
        } else if (f % 2 != 0) {
            ans = min(s, k) - r; 
        } else {
            ans = s - r;
        }
        cout << max(0, ans) << '\n';
    }
    return 0;
}