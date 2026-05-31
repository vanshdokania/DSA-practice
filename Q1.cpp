#include <bits/stdc++.h>
using namespace std;
// 1. given an array of string eg. [eat, tea, tan, ate, nat, bat]
// group anagram - [bat, nat, tan, ate, tea, eat] 
// n = 1e4x
int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    vector<string> input;
    int n;
    cin >> n;
    int t = n;
    while (t--) {
        string str;
        cin >> str;
        input.push_back(str);
    }
    // for (auto s : input) cout << s << " ";
    vector<unordered_map<char, int>> f_map;
    for (auto str : input) {
        unordered_map<char, int> temp;
        for (auto ch : str) {
            temp[ch]++;
        }
        f_map.push_back(temp);
    }
    vector<bool> taken(n, false);
    vector<string> ans;
    for (int i = 0; i < n; i++) {
        unordered_set<string> temp;
        for (int j = i; j < n; j++) {
            if (!taken[j]) {
                if (f_map[i] == f_map[j]) {
                    temp.insert(input[j]);
                    taken[j] = true;
                }
            }
        }
        for (auto s : temp) {
            ans.push_back(s);
        }
        temp.clear();
    }
    cout << '\n';
    for (auto s : ans) cout << s << " ";
    return 0;

}