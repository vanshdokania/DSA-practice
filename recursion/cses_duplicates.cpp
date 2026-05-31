#include <bits/stdc++.h>
#define ll long long 
using namespace std;


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
    set<ll> st; 
    for (ll i = 0; i < n; i++) {
        cin >> arr[i];
        st.insert(arr[i]);
    }
    cout << st.size();

    return 0;
}