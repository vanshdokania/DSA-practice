#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        ll h;
        cin >> n >> m >> h;
        vector<ll> arr(n + 1);
        for (int i = 1; i <= n; i++) cin >> arr[i];
        vector<ll> addition(n + 1, 0);
        vector<ll> status(n + 1, -1);
        int rid = 0;
        for (int k = 0; k < m; k++) {
            int b;
            ll c;
            cin >> b >> c;
            if (status[b] != rid) {
                status[b] = rid;
                addition[b] = 0;
            }
            addition[b] += c;
            if (arr[b] + addition[b] > h) {
                rid++; 
            }
        }
        for (int i = 1; i <= n; i++) {
            ll cur;
            if (status[i] == rid) {
                cur = arr[i] + addition[i];
            } else {
                cur = arr[i];
            }
            cout << cur << (i == n ? '\n' : ' ');
        }
    }
    return 0;
}
