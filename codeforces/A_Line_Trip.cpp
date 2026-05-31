#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) cin >> arr[i];
        arr.push_back(x);
        int maxFront = arr[0];
        for (int i = 1; i < arr.size(); i++) {
            maxFront = max(maxFront, arr[i] - arr[i - 1]);
        }
        int maxBack = 2 * (x - arr[arr.size() - 2]);
        cout << max(maxFront, maxBack) << '\n';
    }
    return 0;
}