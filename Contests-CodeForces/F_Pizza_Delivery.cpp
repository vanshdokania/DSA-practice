#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, Ax, Ay, Bx, By;
        cin >> n >> Ax >> Ay >> Bx >> By;
        vector<pair<int, int>> homes(n);
        vector<bool> delivered(n, false);
        int numberOfDelivery = 0;
        for (int i = 0; i < n; i++) cin >> homes[i].first;
        for (int i = 0; i < n; i++) cin >> homes[i].second;
        pair<int, int> src = {Ax, Ay};
        while (numberOfDelivery != n) {
            int minx = INT_MAX;
            for (int i = 0; i < n; i++) {
                if (!delivered[i]) minx = min(homes[i].first, minx);
            }
        }
    }   
    return 0;
}