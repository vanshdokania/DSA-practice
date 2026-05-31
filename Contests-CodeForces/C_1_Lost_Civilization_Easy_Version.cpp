#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<long long> arr(n);
    for (auto &x : arr) {
        cin >> x;
    }
    vector<long long> stack_like;
    stack_like.reserve(n);
    int segments = 0;
    for (long long x : arr) {

        // Start new segment if empty
        if (stack_like.empty()) {
            segments++;
            stack_like.push_back(x);
            continue;
        }

        // If strictly consecutive increasing
        if (x == stack_like.back() + 1) {
            stack_like.push_back(x);
            continue;
        }

        // Otherwise, remove invalid elements
        while (!stack_like.empty() && stack_like.back() >= x) {
            stack_like.pop_back();
        }

        if (!stack_like.empty() && x == stack_like.back() + 1) {
            stack_like.push_back(x);
        } else {
            segments++;
            stack_like.clear();
            stack_like.push_back(x);
        }
    }

    cout << segments << "\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}