#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<pair<int, int>> arr;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            if (i % 2 == 0) {
                arr.push_back({x, 0});
            } else {
                arr.push_back({x, 1});
            }
        } 
        sort(arr.begin(), arr.end());
        bool flag = true;
        for (int i = 1; i < n; i++) {
            if (arr[i].second == arr[i - 1].second) flag = false;
        }
        if (flag) {
            cout << "YES" << '\n';
        } else {
            cout << "NO" << '\n';
        }
    }
    return 0;
}