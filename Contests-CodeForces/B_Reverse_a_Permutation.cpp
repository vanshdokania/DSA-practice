#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr1(n);
        for (int i = 0; i < n; i++) cin >> arr1[i];
        vector<int> arr2 = arr1;
        sort(arr2.begin(), arr2.end());
        reverse(arr2.begin(), arr2.end());
        int l = 0;
        int r = 0;
        int x = 0;
        for (int i = 0; i < n; i++) {
            if (arr1[i] < arr2[i]) {
                x = arr2[i];
                l = i;
                break;
            }
        }
        for (int i = n - 1; i >= 0; i--) {
            if (arr1[i] == x) {
                r = i;
                break;
            }
        }
        while (l < r) {
            swap(arr1[l], arr1[r]);
            l++;
            r--;
        }
        for (int x : arr1) cout << x << " ";
        cout << '\n';
    }
    return 0;
}