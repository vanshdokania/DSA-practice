#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> graph(n + 1);
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    vector<int> team(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        if (team[i] != 0) continue;
        queue<int> q;
        q.push(i);
        team[i] = 1;
        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            for (auto neigh : graph[curr]) {
                if (team[neigh] == 0) {
                    team[neigh] = 3 - team[curr];
                    q.push(neigh);
                }
                else if (team[neigh] == team[curr]) {
                    cout << "IMPOSSIBLE";
                    return 0;
                }
            }
        }
    }
    for (int i = 1; i <= n; i++) cout << team[i] << " ";
}