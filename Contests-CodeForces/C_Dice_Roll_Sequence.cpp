#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n + 1);
        arr[0] = -1;
        for (int i = 1; i <= n; i++) {
            cin >> arr[i];
        }
        int count = 0;
        for (int i = 1; i < n; i++) {
            if ((i == n - 1) && (arr[i] == arr[i + 1] || arr[i] + arr[i + 1] == 7)) {
                count++;
                break;
            }
            if (arr[i] == arr[i + 1] || arr[i] + arr[i + 1] == 7) {
                count++;
                i++;
            }
        }
        cout << count << "\n";
    }
    return 0;
}