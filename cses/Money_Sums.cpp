#include <bits/stdc++.h>
using namespace std;
set<int> ans;
vector<vector<int>> dp;
vector<int> nums;
int n;
bool f(int idx, int sum) {
    if (sum == 0) return true;
    if (sum < 0 || idx == n) return false;
    if (dp[idx][sum] != -1) return dp[idx][sum];
    bool take = f(idx + 1, sum - nums[idx]);
    bool skip = f(idx + 1, sum);
    return dp[idx][sum] = (take || skip);
}

int main() {
    cin >> n;
    nums.resize(n);
    int total = 0;
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
        total += nums[i];
    }
    dp.assign(n, vector<int>(total + 1, -1));
    for (int s = 1; s <= total; s++) if (f(0, s)) ans.insert(s);
    cout << ans.size() << "\n";
    vector<int> fans;
    for (int x : ans) fans.push_back(x);
    sort(fans.begin(), fans.end());
    for (int i = 0; i < fans.size(); i++) cout << fans[i] << " ";
    cout << "\n";
    return 0;
}
