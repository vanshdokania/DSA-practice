#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    ll n;
    cin >> n;
    ll s = (n * (n + 1)) / 2;
    if (s % 2 != 0) cout << "NO"; 
    else {
        cout << "YES";
        cout << "\n";
        ll target = s / 2;
        vector<ll> a, b;
        vector<bool> used(n + 1, false);
        for (ll i = n; i >= 1; i--) {
            if (i <= target) {
                a.push_back(i);
                used[i] = true;
                target -= i;
            }
        }
        for (ll i = 1; i <= n; i++) {
            if (!used[i]) b.push_back(i);
        }
        cout << a.size() << "\n";
        for (ll x : a) cout << x << " ";
        cout << "\n";
        cout << b.size() << "\n";
        for (ll x : b) cout << x << " ";
        cout << "\n";
    }
    return 0;
}