#include<bits/stdc++.h>
using namespace std;
#define ll long long int

ll f(vector<ll>& arr, ll a, ll b, ll idx, ll ans) {
    if (idx == arr.size()) {
        ans = min(ans, abs(a - b));
        return ans;
    }
    ll opt1 = f(arr, a + arr[idx], b, idx + 1, ans);
    ll opt2 = f(arr, a, b + arr[idx], idx + 1, ans);
    return ans = min(opt1, opt2);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    ll n;
    cin >> n;
    vector<ll> arr(n);
    for (ll i = 0; i < n; i++) cin >> arr[i];
    cout << f(arr, 0, 0, 0, INT_MAX);
    return 0;
}