#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    string s;
    cin >> s;
    map<char, ll> mp;
    for (char ch : s) mp[ch]++;
    ll odd_count = 0;
    char mid;
    for (auto x : mp) if (x.second % 2 != 0) {
        odd_count++;
        mid = x.first;
    }
    if (odd_count > 1) {
        cout << "NO SOLUTION";
        return 0;
    }
    string left = "";
    string middle = "";
    string right = "";
    for (auto x : mp) left += string(x.second / 2, x.first);
    if (odd_count == 1) middle = string(mp[mid] % 2, mid);
    right = left;
    reverse(right.begin(), right.end());
    cout << left << middle << right;
    return 0;
}