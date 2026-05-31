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
    ll i = 0;
    ll j = s.size() - 1;
    while (i <= j) {
        if (s[i] == s[j]) {
            i++;
            j--;
            continue;
        } else {
            ll k = j;
            while (j > i && s[j] != s[i]) j--;
            swap(s[k], s[j]);
            j = k;
            i++;
            j--;
        }
    }
    i = 0;
    j = s.size() - 1;
    while (i <= j) {
        if (s[i] != s[j]) {
            cout << "NO SOLUTION";
            return 0;
        }
        i++;
        j--;
    }
    cout << s;
    return 0;
}