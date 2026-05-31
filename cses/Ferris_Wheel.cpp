#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);
    // #ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // #endif
    int n, x;
    cin >> n >> x;
    vector<int> weights(n);
    for (int i = 0; i < n; i++) cin >> weights[i];
    sort(weights.begin(), weights.end());
    int i = 0;
    int j = n - 1;
    int count = 0;
    while (i < j) {
        if (weights[i] + weights[j] <= x) {
            count++;
            i++;
            j--;
        } else {
            count++;
            j--;
        }
    }
    if (i == j) count++;
    cout << count;
    return 0;
}