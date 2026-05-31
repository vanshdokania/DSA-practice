#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<double> c(n), p(n);
        for (int i = 0; i < n; ++i) cin >> c[i] >> p[i];
        double ans = 0;
        for (int i = n - 1; i >= 0; i--) {
            ans = max(ans, c[i] + (1.0 - (p[i] / 100.0)) * ans);
        }
        cout << fixed << setprecision(10) << ans << "\n";
    }
    return 0;
}
