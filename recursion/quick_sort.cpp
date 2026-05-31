#include <bits/stdc++.h>
using namespace std;

int f(vector<int>& arr, int n, int lo, int hi) {
    int i = lo + 1;
    int j = hi;
    while (i < j) {
        while (i <= hi && arr[lo] > arr[i]) i++;
        while (j >= lo && arr[lo] < arr[j]) j--;
        if (i < j) swap(arr[i], arr[j]);
    } 
    swap(arr[lo], arr[j]);
    return j;
}

void quickSort(vector<int>& arr, int n, int lo, int hi) {
    if (lo >= hi) return;
    int pivotIdx = f(arr, n, lo, hi);
    quickSort(arr, n, lo, pivotIdx - 1);
    quickSort(arr, n, pivotIdx + 1, hi);
    return;
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
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    quickSort(arr, n, 0, n - 1);

    for(int i = 0; i < n; i++) cout << arr[i] << " ";
    return 0;
}