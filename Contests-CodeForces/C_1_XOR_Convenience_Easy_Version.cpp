#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n + 1);
        arr[n] = 1;
        for (int i = 2; i <= n - 1; i++) arr[i] = (i ^ 1);
        if (n % 2 == 0) arr[1] = n;
        else arr[1] = n - 1;
        for (int i = 1; i <= n; i++) cout << arr[i] << " ";
        cout << '\n';
    }
    return 0;
}
