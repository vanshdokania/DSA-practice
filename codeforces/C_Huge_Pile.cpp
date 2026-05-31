#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        long long n, k;
        cin >> n >> k;

        if (k > n) {
            cout << -1 << '\n';
            continue;
        }

        long long steps = 0;
        while (n > k) {
            n = (n + 1) / 2;
            steps++;
        }

        if (n == k) cout << steps << '\n';
        else cout << -1 << '\n';
    }
    return 0;
}
