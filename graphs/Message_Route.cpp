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
    queue<int> q;
    vector<bool> vis(n + 1, false);
    vector<int> parent(n + 1, -1);
    q.push(1);
    vis[1] = true;
    while (!q.empty()) {
        int curr = q.front();
        q.pop();
        for (auto neigh : graph[curr]) {
            if (!vis[neigh]) {
                vis[neigh] = true;
                parent[neigh] = curr;
                q.push(neigh);
            }
        }
    }
    if (!vis[n]) {
        cout << "IMPOSSIBLE\n";
        return 0;
    }
    vector<int> path;
    int v = n;
    while (v != -1) {
        path.push_back(v);
        v = parent[v];
    }
    reverse(path.begin(), path.end());
    cout << path.size() << "\n";
    for (int x : path) cout << x << " ";
}