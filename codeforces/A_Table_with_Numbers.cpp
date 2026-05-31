#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, l , h;
        cin >> n >> l >> h;
        vector<pair<int, bool>> arr;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            if (x <= l || x <= h) arr.push_back({x, false});
        }
        sort(arr.begin(), arr.end());
        reverse(arr.begin(), arr.end());
        int count = 0;
        for (int i = 0; i < arr.size(); i++) {
            if (arr[i].second == true) continue;
            for (int j = 0; j < arr.size(); j++) {
                if (i != j && arr[j].second == false) {
                    if ((arr[i].first <= l && arr[j].first <= h) || (arr[i].first <= h && arr[j].first <= l)) {
                        count++;
                        arr[i].second = true;
                        arr[j].second = true;
                        break;
                    }
                }
            }
        }
        cout << count << '\n';
    }
    return 0;
}