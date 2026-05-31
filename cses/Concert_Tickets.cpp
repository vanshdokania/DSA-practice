#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int n, m;
    cin >> n >> m;
    vector<int> tickets(n);
    vector<int> customers(m);
    for (int i = 0; i < n; i++) cin >> tickets[i];
    for (int j = 0; j < m; j++) cin >> customers[j];
    sort(tickets.begin(), tickets.end());
    sort(customers.begin(), customers.end());
    int i = 0;
    int j = 0;
    vector<int> ans;
    while (i < n && j < m) {
        if (tickets[i] <= customers[j]) {
            i++;
            j++;
            ans.push_back(tickets[i]);
        } else {
            i++;
            j++; 
            ans.push_back(-1);
        }
    }
    for (int i = 0; i < ans.size(); i++) cout << ans[i] << " ";
    return 0;
}