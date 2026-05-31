#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int s, k, m;
        cin >> s >> k >> m;
        int cycles = m / k;
        int remain = m % k;
        int ans = 0;
        if (cycles == 0) {
            ans = s - m;
        } else if (cycles % 2 == 1) {
            ans = min(s, k) - remain;
        } else {
            ans = s - remain;
        }
        cout << max(0, ans) << '\n';
    }
    
    return 0;
}