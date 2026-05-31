#include <bits/stdc++.h>
using namespace std;
#define ll long long int

void f(ll n, int src, int helper, int dest) {
    if (n == 0) return;
    f(n - 1, src, dest, helper);
    cout << src << " " << dest << "\n";
    f(n - 1, helper, src, dest);
}

int main() {
     
    ll n;
    cin >> n;
    cout << (1 << n) - 1 << "\n";
    f(n, 1, 2, 3);
    return 0;
}