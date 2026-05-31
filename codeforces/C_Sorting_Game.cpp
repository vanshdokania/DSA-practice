#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        if (is_sorted(s.begin(), s.end())) {
            cout << "Bob\n";
            continue;
        }
        int zeroCount = 0;
        for (char ch : s) {
            if (ch == '0') zeroCount++;
        }
        vector<int> idx;
        for (int i = 0; i < zeroCount; ++i) {
            if (s[i] == '1') idx.push_back(i + 1);
        }
        for (int i = zeroCount; i < n; ++i) {
            if (s[i] == '0') idx.push_back(i + 1);
        }
        cout << "Alice\n";
        cout << idx.size() << "\n";
        for (int x : idx) cout << x << " ";
        cout << "\n";
    }
    return 0;
}
