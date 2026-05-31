#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int ans = 0;
        int currAns = 0;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            if (x == 0) {
                currAns++;
            } else {
                ans = max(currAns, ans);
                currAns = 0;
            }
        }
        ans = max(currAns, ans);
        cout << ans << '\n';
    }
    return 0;
}