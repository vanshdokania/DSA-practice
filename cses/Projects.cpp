#include <bits/stdc++.h>
using namespace std;

// int f(int n, vector<pair<int, int>>& days, vector<int>& money, int idx, int prevEndDay) {
//     if (idx == n) return 0;
//     int profit = 0;
//     for (int i = 0; i < n; i++) {
//         if (i == idx) continue;
//         if (days[i].first > prevEndDay) {
//             profit += money[i];
//         }

//     }

// }

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int n;
    cin >> n;
    vector<pair<int, int>> days(n);
    vector<int> money(n);
    for (int i = 0; i < n; i++) {
        cin >> days[i].first >> days[i].second >> money[i];
    }
    int profit = 0;
    int prevEndDay = -1;
    for (int i = 0; i < n; i++) {
        int currProfit = money[i];
        prevEndDay = days[i].second;
        for (int j = 0; j < n; j++) {
            if (i == j) continue;
            if (days[j].first > prevEndDay) {
                currProfit += money[j];
                prevEndDay = days[j].second;
            }
        }
        profit = max(profit, currProfit);
    }
    cout << profit;
    return 0;
}