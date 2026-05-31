#include <bits/stdc++.h>
using namespace std;
#define ll long long int

void f(vector<string>& perms, vector<bool>& used, string& s, string& curr, int idx) {
    if (idx == s.size()) {
        perms.push_back(curr);
        return;
    }
    for (int i = 0; i < s.size(); i++) {
        if (used[i]) continue;
        used[i] = true;
        curr += s[i];
        f(perms, used, s, curr, idx + 1);
        curr.pop_back();
        used[i] = false;
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
    string s;
    cin >> s;
    vector<string> perms;
    string curr = "";
    vector<bool> used(s.size(), false);
    f(perms, used, s, curr, 0);
    set<string> st;
    for (auto x : perms) st.insert(x);
    vector<string> perms2;
    for (auto x : st) perms2.push_back(x);
    cout << perms2.size() << '\n';
    for (auto x : perms2) cout << x << "\n";
    return 0;
}