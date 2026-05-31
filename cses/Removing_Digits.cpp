#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int maxDig(int n) {
    int maxi = 0;
    while (n > 0) {
        int r = n % 10;
        n = n / 10;
        maxi = max(maxi, r); 
    }
    return maxi;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int n;
    cin >> n;
    int count = 0;
    while (n > 9) {
        n = n - maxDig(n);
        count++;
    }
    cout << count + 1;
    return 0;
}