#include <bits/stdc++.h>
using namespace std;

void f(int i, int sum, int n){
    if(i == n) {
        sum += i;
        cout << sum;
        return;
    }
    sum += i;
    i++;
    f(i, sum, n);
    return;
}
int main(){

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int n;
    cin >> n;
    f(0, 0, n);
    return 0;
}