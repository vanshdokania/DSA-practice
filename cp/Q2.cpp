#include <bits/stdc++.h>
using namespace std;
int mex(int n, vector<int>& arr, int k) {
    int maxIdx = 0;
    for (int i = 0; i <= n - k; i++) {
        if (arr[maxIdx] < findMexInWindow(arr, i, k)) maxIdx = i;
    }
    return maxIdx;
}
int findMexInWindow(vector<int>& arr, int i, int k) {
    vector<int> parent(1000001, 0);
    for (int j = i; j <= i + k - 1; j++) {
        parent[arr[j]]++;
    }
    for (int x = 0; x < parent.size(); x++) {
        if (parent[x] == 0) return parent[x];
    }
}
int findMex(vector<int>& arr) {
    int i = 0;
    vector<int> parent(1000001, 0);
    for (int i = 0; i < arr.size(); i++) parent[arr[i]]++;
    for (int i = 0; i < parent.size(); i++) {
        if (parent[i] == 0) return parent[i];
    }
}
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
        int n, k;
        cin >> n >> k;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) cin >> arr[i];
        while (arr.size() != k - 1) {
            int l = mex(n, arr, k);
            int r = l + k - 1;
            int maxIdx = l;
            for (int i = l; i <= r; i++) {
                if (arr[maxIdx] < arr[i]) maxIdx = i;
            }
            arr.erase(arr.begin() + maxIdx);
        }
        if (arr.size() == k - 1) {
            int maxIdx = 0;
            for (int i = 0; i < arr.size(); i++) {
                if (arr[maxIdx] < arr[i]) maxIdx = i;
            }
            arr.erase(arr.begin() + maxIdx);
        }
        cout << findMex(arr);
    }
    return 0;
}