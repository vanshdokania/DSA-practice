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
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> apparts(m);
    vector<int> req(n);
    for (int i = 0; i < n; i++) cin >> req[i];
    for (int j = 0; j < m; j++) cin >> apparts[j];
    sort(apparts.begin(), apparts.end());
    sort(req.begin(), req.end());
    int count = 0;
    int i = 0;
    int j = 0;
    while (i < n && j < m) {
        if (apparts[j] < req[i] - k) j++;
        else if (apparts[j] > req[i] + k) i++;
        else {
            count++;
            i++;
            j++;
        }
    }
    cout << count;
    return 0;
}