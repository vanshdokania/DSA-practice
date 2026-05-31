#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main() {
    ll n;
    cin >> n;
    vector<ll> nums(n);
    for (ll i = 0; i < n; i++) cin >> nums[i];
    vector<int> sorted;
    sorted.push_back(nums[0]);
    for (ll i = 1; i < n; i++) {
        auto it = lower_bound(sorted.begin(), sorted.end(), nums[i]);
        if (it == sorted.end()) {
            sorted.push_back(nums[i]);
        } else {
            *it = nums[i];
        }
    }
    cout << sorted.size();
    return 0;
}   