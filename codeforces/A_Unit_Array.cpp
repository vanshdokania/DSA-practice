#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int ones = 0, mones = 0;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            if (x == 1) ones++;
            else mones++;
        }
        int ans = 0;
        while (ones < mones || mones % 2 == 1) { 
            ans++; 
            ones++; 
            mones--; 
        }\
        cout << ans << endl;
    }
    return 0;
}
