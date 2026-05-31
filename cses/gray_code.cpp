#include <bits/stdc++.h>
using namespace std;
#define ll long long int

void f(ll n, vector<string>& ans) {
    if (n == 1) {
        ans.push_back("0");
        ans.push_back("1");
        return;
    }
    f(n - 1, ans);
    vector<string> temp = ans;
    reverse(temp.begin(), temp.end());
    ans.insert(ans.end(), temp.begin(), temp.end());
    for (ll i = 0; i < ans.size() / 2; i++) {
        ans[i] = "0" + ans[i];
    }
    for (ll i = ans.size() / 2; i < ans.size(); i++) {
        ans[i] = "1" + ans[i];
    }
    return;
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
    vector<string> ans;
    f(n, ans);
    for (ll i = 0; i < ans.size(); i++) cout << ans[i] << "\n";
    return 0;
}