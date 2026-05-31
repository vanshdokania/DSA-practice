#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<ll> f(n);
        for (int i = 0; i < n; i++) {
            cin >> f[i];
        }
        vector<ll> arr(n, 0);
        ll sum_middle = 0;
        ll weighted_middle = 0;
        for (int i = 1; i <= n - 2; i++) {
            ll left  = f[i - 1] - f[i];
            ll right = f[i + 1] - f[i];
            arr[i] = (left + right) / 2;
            sum_middle += arr[i];
            weighted_middle += arr[i] * i;
        }
        arr[n - 1] = (f[0] - weighted_middle) / (n - 1);
        arr[0] = f[1] - f[0] + sum_middle + arr[n - 1];
        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << '\n';
    }
    return 0;
}
