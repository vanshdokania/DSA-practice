#include <bits/stdc++.h>
using namespace std;

void f(int i, vector<int> arr, int n,vector<int> sarr) {
    if (i == n) {
        for (int x : sarr) cout << x;
        cout << '\n';
        return;
    }
    sarr.push_back(arr[i]);
    f(i + 1, arr, n, sarr);
    sarr.pop_back();
    f(i + 1, arr, n, sarr);
}


int main(){

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int n;
    cin >> n;
    vector<int> arr(n);
    vector<int> sarr;
    for (int i = 0; i < n; i++) cin >> arr[i];
    // f(0, arr, n, sarr);

    for (int i = 0; i < (1 << n); i++) {
        for (int j = 0; j < n; j++) {
            if (i & (1 << j)) {
                cout << arr[j] << " ";
            }
        }
        cout << '\n';
    }
    return 0;


}