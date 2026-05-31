#include <bits/stdc++.h>
using namespace std;
#define ll long long int
static const ll MODULO = 998244353;
static const int PHASES = 4;
int main() {
    int tests;
    cin >> tests;
    while (tests--) {
        int L;
        string seq;
        cin >> L >> seq;
        vector<array<ll, PHASES>> waysCnt(L + 3), waysSum(L + 3);
        vector<array<ll, PHASES>> nextCnt(L + 3), nextSum(L + 3);
        for (int i = 0; i <= L + 2; i++) {
            waysCnt[i].fill(0);
            waysSum[i].fill(0);
        }
        waysCnt[0][0] = 1;
        for (char c : seq) {
            for (int i = 0; i <= L + 2; i++) {
                nextCnt[i] = waysCnt[i];
                nextSum[i] = waysSum[i];
            }
            for (int openCnt = 0; openCnt <= L; openCnt++) {
                for (int phase = 0; phase < PHASES; phase++) {
                    ll curWays = waysCnt[openCnt][phase];
                    if (curWays == 0) continue;
                    ll curSum = waysSum[openCnt][phase];
                    if (c == '(') {
                        int newOpen = openCnt + 1;
                        int newPhase = phase;
                        if (phase == 1) newPhase = 2;
                        else if (phase == 2 || phase == 3) newPhase = 3;
                        nextCnt[newOpen][newPhase] =
                            (nextCnt[newOpen][newPhase] + curWays) % MODULO;
                        nextSum[newOpen][newPhase] =
                            (nextSum[newOpen][newPhase] + curSum + curWays) % MODULO;
                    } 
                    else {
                        if (openCnt == 0) continue;
                        int newOpen = openCnt - 1;
                        int newPhase = (phase == 0 ? 1 : phase);
                        nextCnt[newOpen][newPhase] =
                            (nextCnt[newOpen][newPhase] + curWays) % MODULO;
                        nextSum[newOpen][newPhase] =
                            (nextSum[newOpen][newPhase] + curSum + curWays) % MODULO;
                    }
                }
            }
            waysCnt.swap(nextCnt);
            waysSum.swap(nextSum);
        }
        ll result = (waysSum[0][3] - 2LL * waysCnt[0][3]) % MODULO;
        if (result < 0) result += MODULO;
        cout << result << '\n';
    }
    return 0;
}
