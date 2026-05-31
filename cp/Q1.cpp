#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) cin >> arr[i];
        if (arr[0] == 1 || arr[n - 1] == 1) {
            cout << "Alice" << '\n';
            continue;
        } else {
            cout << "Bob" << '\n';
            continue;
        }
    }
    
    return 0;
}