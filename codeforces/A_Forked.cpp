#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int a, b;
        cin >> a >> b;
        int kx, ky;
        cin >> kx >> ky;
        int qx, qy;
        cin >> qx >> qy;
        set<pair<int, int>> kingMoves;
        set<pair<int, int>> queenMoves;
        vector<pair<int, int>> moves = {
            {a, b}, {b, a}, {a, -b}, {-b, a},
            {-a, -b}, {-b, -a}, {b, -a}, {-a, b}
        };
        for (auto x : moves)
            kingMoves.insert({kx + x.first, ky + x.second});
        for (auto x : moves)
            queenMoves.insert({qx + x.first, qy + x.second});
        int ans = 0;
        for (auto &pos : kingMoves) {
            if (queenMoves.count(pos) != 0) ans++;
        }
        cout << ans << '\n';
    }
    return 0;
}
