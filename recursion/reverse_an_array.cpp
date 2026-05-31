#include <bits/stdc++.h>
using namespace std;

void f(int i, int arr[], int n) {
    if(i == n/2) return;
    int temp = arr[i];
    arr[i] = arr[n - i - 1];
    arr[n - i - 1] = temp;
    i++;
    f(i, arr, n);
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
    int arr[n];
    for (int i = 0; i < n; i++) cin >> arr[i];
    f(0, arr, n);
    for (int i = 0; i < n; i++) cout << arr[i] << ' ';

    return 0;
}