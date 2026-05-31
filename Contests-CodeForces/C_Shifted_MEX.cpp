#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; ++i) {
            cin >> arr[i];
        }
        sort(arr.begin(), arr.end());
        int longest_chain = 1;
        int current_chain = 1;
        for (ll i = 1; i < arr.size(); i++) {
            if (arr[i] == arr[i - 1]) {
                continue;
            }
            if (arr[i] == arr[i - 1] + 1) {
                current_chain++;
            } else {
                longest_chain = max(longest_chain, current_chain);
                current_chain = 1;
            }
        }
        longest_chain = max(longest_chain, current_chain);
        cout << longest_chain << "\n";
    }
    return 0;
}
