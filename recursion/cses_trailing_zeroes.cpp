#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    ll n;
    cin >> n;
    ll count = 0;
    ll i = 5;
    while (i <= n) {
        count += n / i;
        i *= 5;
    }
    cout << count;
    
    return 0;
}