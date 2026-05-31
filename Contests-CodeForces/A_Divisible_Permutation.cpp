#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        arr[n - 1] = n;
        bool flag = false;
        for (int i = n - 2; i >= 0; i--) {
            if (!flag) {
                arr[i] = arr[i + 1] - (i + 1);
            } else {
                arr[i] = arr[i + 1] + (i + 1);
            }
            flag = !flag;
        }
        for (int x : arr) cout << x << " ";
        cout << '\n';
    }
    return 0;
}