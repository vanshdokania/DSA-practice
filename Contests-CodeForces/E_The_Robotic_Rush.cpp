// #include <bits/stdc++.h>
// using namespace std;
// #define ll long long int

// int main() {
//     ll t;
//     cin >> t;
//     while (t--) {
//         ll n, m, k;
//         cin >> n >> m >> k;
//         vector<ll> robots(n);
//         vector<ll> spikes(m);
//         sort(spikes.begin(), spikes.end());
//         string instructions;
//         for (ll i = 0; i < n; i++) cin >> robots[i];
//         for (ll i = 0; i < m; i++) cin >> spikes[i];
//         cin >> instructions;
//         vector<ll> ans;
//         for (char ch : instructions) {
//             if (ch == 'L') {
//                 for (ll i = 0; i < n; i++) {
//                     robots[i]--;
//                 }
//             } else if (ch == 'R') {
//                 for (ll i = 0; i < n; i++) {
//                     robots[i]++;
//                 }
//             }
//             for (ll i = 0; i < robots.size(); i++) {
//                 for (ll j = 0; j < m; j++) {
//                     if (robots[i] == spikes[j]) {
//                         robots.erase(robots.begin() + i);
//                     }
//                 }
//             }
//             cout << robots.size() << " ";
//         }
//         cout << '\n';
//     }
//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;
#define ll long long int
static const int MOD = 1e9;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, k;
        cin >> n >> m >> k;
        vector<ll> robotPos(n), spikePos(m);
        for (auto &x : robotPos) cin >> x;
        for (auto &x : spikePos) cin >> x;
        sort(spikePos.begin(), spikePos.end());
        string moves;
        cin >> moves;
        vector<int> rightReach(k + 2, 0), leftReach(k + 2, 0);
        int displacement = 0;
        int maxRight = 0, maxLeft = 0;
        for (int step = 1; step <= k; step++) {
            displacement += (moves[step - 1] == 'R' ? 1 : -1);
            if (displacement > maxRight) {
                maxRight = displacement;
                rightReach[maxRight] = step;
            }
            if (displacement < maxLeft) {
                maxLeft = displacement;
                leftReach[-maxLeft] = step;
            }
        }
        vector<int> killedAt(k + 2, 0);
        for (long long pos : robotPos) {
            int earliestDeath = MOD;
            auto it = lower_bound(spikePos.begin(), spikePos.end(), pos);
            if (it != spikePos.end()) {
                long long dist = *it - pos;
                if (dist > 0 && dist <= maxRight) {
                    earliestDeath = min(earliestDeath, rightReach[(int)dist]);
                }
            }
            if (it != spikePos.begin()) {
                auto pit = prev(it);
                long long dist = pos - *pit;
                if (dist > 0 && dist <= -maxLeft) {
                    earliestDeath = min(earliestDeath, leftReach[(int)dist]);
                }
            }
            if (earliestDeath != MOD) {
                killedAt[earliestDeath]++;
            }
        }
        int totalDead = 0;
        for (int step = 1; step <= k; step++) {
            totalDead += killedAt[step];
            cout << (n - totalDead) << (step == k ? '\n' : ' ');
        }
    }
    return 0;
}

