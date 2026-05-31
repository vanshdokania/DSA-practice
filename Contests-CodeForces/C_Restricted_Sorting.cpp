#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        int mn = INT_MAX;
        int mx = INT_MIN;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            mn = min(mn, a[i]);
            mx = max(mx, a[i]);
        }
        bool sorted = true;
        for (int i = 1; i < n; i++) {
            if (a[i] < a[i - 1]) {
                sorted = false;
                break;
            }
        }
        if (sorted) {
            cout << -1 << '\n';
            continue;
        }
        vector<int> sortedA = a;
        sort(sortedA.begin(), sortedA.end());
        int lo = 1, hi = 1e9, ans = 1;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            ll upper = mx - mid; 
            ll lower = mn + mid; 
            bool ok = true;
            if (upper < lower) {
                for (int i = 0; i < n; i++) {
                    if (a[i] > upper && a[i] < lower) {
                        if (a[i] != sortedA[i]) {
                            ok = false;
                            break;
                        }
                    }
                }
            }
            if (ok) {
                ans = mid;
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        cout << ans << '\n';
    }

    return 0;
}
