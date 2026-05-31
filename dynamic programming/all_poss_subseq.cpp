#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> subseq;
void f(int idx, vector<int>& curr, vector<int>& arr) {
    if (idx == arr.size()) {
        subseq.push_back(curr);
        return;
    }
    curr.push_back(arr[idx]);
    f(idx + 1, curr, arr);
    curr.pop_back();
    f(idx + 1, curr, arr);
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
    vector<int> curr;
    f(0, curr, arr);
    for (int i = 0; i < subseq.size(); i++) {
        for (int j = 0; j < subseq[i].size(); j++) {
            cout << subseq[i][j] << " ";
        }
        cout << '\n';
    }
    return 0;

}