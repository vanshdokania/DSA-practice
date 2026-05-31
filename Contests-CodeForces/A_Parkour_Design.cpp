#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        long long x, y;
        cin >> x >> y;
        long long val = x - 2LL * y;
        bool possible = true;
        if (val % 3 != 0) possible = false;
        else {
            if (y >= 0) possible = (x >= 2LL * y);
            else possible = (x >= -4LL * y);
        }
        cout << (possible ? "YES\n" : "NO\n");
    }

    return 0;
}