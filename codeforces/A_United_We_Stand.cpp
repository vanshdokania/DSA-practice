#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        bool ok = true;
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
            if (i != 0 && arr[i] != arr[i - 1]) ok = false;
        }
        if (ok) {
            cout << -1 << '\n';
            continue;
        }

        sort(arr.begin(), arr.end());
        vector<int> a;
        vector<int> b;
        for (int i = 0; i < n - 1; i++) {
            a.push_back(arr[i]);
        }
        b.push_back(arr[arr.size() - 1]);
        for (int i = a.size() - 1; i >= 0; i--) {
            if (a[i] == b[0]) {
                b.push_back(a[i]);
                a.pop_back();
            } else {
                break;
            }
        } 
        cout << a.size() << " " << b.size() << '\n';
        for (int i = 0; i < a.size(); i++) cout << a[i] << " ";
        cout << '\n';
        for (int i = 0; i < b.size(); i++) cout << b[i] << " ";
    }
    return 0;
}