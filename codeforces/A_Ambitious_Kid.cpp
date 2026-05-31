#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    int ans = INT_MAX;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        arr[i] = abs(x);
        ans = min(ans, arr[i]);
    }
    cout << ans;
    return 0;
}