#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main() {
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