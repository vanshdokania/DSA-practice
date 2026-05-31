#include <bits/stdc++.h>
using namespace std;



void f(int counter) {
    if(counter == 100) return;
    counter++;
    f(counter);
    cout << counter;
    cout << '\n';
    return;
}


int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    f(0);

    return 0;
}
