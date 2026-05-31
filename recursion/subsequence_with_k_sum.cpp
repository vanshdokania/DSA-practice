#include <bits/stdc++.h>
using namespace std;

void f (vector<int> arr, int n, int k, int i, vector<int> sarr) {
    if (accumulate(sarr.begin(), sarr.end(), 0) > k) return;
    if (i == n) {
        int sum = accumulate(sarr.begin(), sarr.end(), 0);
        if (sum != k) return;
        else {
            for (int x : sarr) cout << x << " ";
            cout << '\n';
        }
        return;
    }
    if (arr[i] <= k) {
        sarr.push_back(arr[i]);
        f(arr, n, k, i + 1, sarr);
    }
    sarr.pop_back();
    f(arr, n, k, i + 1, sarr);
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int n;
    int k;
    cin >> n >> k;
    vector<int> arr(n, 0);
    for (int i = 0; i < n; i++) cin >> arr[i];
    
    f(arr, n, k, 0, {});

    return 0;
}