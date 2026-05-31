#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> dp;

int f(int i, int j, vector<int>& a, vector<int>& b) {
    if (i == a.size() || j == b.size()) return 0;
    if (dp[i][j] != -1) return dp[i][j];
    if (a[i] == b[j]) return dp[i][j] = 1 + f(i + 1, j + 1, a, b);
    return dp[i][j] = max(f(i + 1, j, a, b), f(i, j + 1, a, b));
}

vector<int> buildLCS(vector<int>& a, vector<int>& b) {
    int i = 0, j = 0;
    vector<int> lcs;
    while (i < a.size() && j < b.size()) {
        if (a[i] == b[j]) {
            lcs.push_back(a[i]);
            i++; j++;
        } 
        else if (i + 1 < a.size() && dp[i + 1][j] >= dp[i][j + 1]) {
            i++;
        } 
        else {
            j++;
        }
    }
    return lcs;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int n, m;
    cin >> n >> m;
    vector<int> arr1(n), arr2(m);
    for (int i = 0; i < n; i++) cin >> arr1[i];
    for (int i = 0; i < m; i++) cin >> arr2[i];
    dp.assign(n, vector<int>(m, -1));
    int len = f(0, 0, arr1, arr2);
    cout << len << "\n";
    vector<int> lcs = buildLCS(arr1, arr2);
    for (int x : lcs) cout << x << " ";
    return 0;
}
