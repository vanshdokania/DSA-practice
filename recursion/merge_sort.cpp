#include <bits/stdc++.h>
using namespace std;

void merge(int n, int lo, int hi, int mid, vector<int>& arr) {
    int a = lo;
    int b = mid + 1;
    vector<int> temp;
    while (a <= mid && b <= hi) {
        if (arr[a] < arr[b]) {
            temp.push_back(arr[a]);
            a++;
        } else {
            temp.push_back(arr[b]);
            b++;
        }
    }
    while (a <= mid) {
        temp.push_back(arr[a]);
        a++;
    }
    while (b <= hi) {
        temp.push_back(arr[b]);
        b++;
    }
    for (int i = lo; i <= hi; i++) {
        arr[i] = temp[i - lo];
    }
    return;
}

void mergeSort(int n, int lo, int hi, vector<int>& arr) {
    if (lo >= hi) return;
    int mid = lo + ((hi - lo) / 2);
    mergeSort(n, lo, mid, arr);
    mergeSort(n, mid + 1, hi, arr);
    merge(n, lo, hi, mid, arr);
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

    mergeSort(n, 0, n - 1, arr);

    for (int i = 0; i < n; i++) cout << arr[i] << " ";    

    return 0;
}