#include <bits/stdc++.h>
using namespace std;


vector<vector<int>> allSubsets;
void f(vector<int>& arr, vector<int>& curr, int idx) {
    allSubsets.push_back(curr);
    for (int i = idx; i < arr.size(); i++) {
        curr.push_back(arr[i]);
        f(arr, curr, i + 1);
        curr.pop_back();
    }
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int n;
    int d;
    cin >> n;
    vector<int> arr(n);
    vector<int> curr;
    for (int i = 0; i < n; i++) cin >> arr[i];
    cin >> d;
    f(arr, curr, 0);
    // for (int i = 0; i < allSubsets.size(); i++) {
    //     for (int j = 0; j < allSubsets[i].size(); j++) {
    //         cout << allSubsets[i][j] << " ";
    //     }
    //     cout << '\n';
    // }
    vector<vector<int>> possibleAns;
    for (auto x : allSubsets) if (x.size() == d) possibleAns.push_back(x);
    return 0;
}