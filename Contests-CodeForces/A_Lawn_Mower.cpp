#include <bits/stdc++.h>
#define ll long long int
using namespace std;
int main() {
    int t;
    cin >> t;
    while (t--) {
        ll n;
        ll w;
        cin >> n >> w;
        cout << n - (n / w) << "\n";
    }
    return 0;
}
