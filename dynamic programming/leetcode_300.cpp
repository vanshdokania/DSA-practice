#include <bits/stdc++.h>
using namespace std;

int f(vector<int>& arr, int idx, int prevIdx) {
    if (idx == arr.size()) return 0;
    int skip = f(arr, idx + 1, prevIdx);
    int take = 0;
    if (prevIdx == -1 || arr[idx] > arr[prevIdx]) {
        take = 1 + f(arr, idx + 1, idx);
    }
    return max(skip, take);
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[n];

    cout << f(arr, 0, -1);

    return 0;
}