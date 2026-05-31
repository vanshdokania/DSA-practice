#include <bits/stdc++.h>
using namespace std;

int cycle_start = -1, cycle_end = -1;

void dfs(vector<vector<int>>& graph, int node, vector<bool>& vis, vector<int>& parent) {
    vis[node] = true;
    for (auto neigh : graph[node]) {
        if (neigh == parent[node]) continue;
        if (vis[neigh]) {
            cycle_start = neigh;
            cycle_end = node;
            return;
        }
        parent[neigh] = node;
        dfs(graph, neigh, vis, parent);
        if (cycle_start != -1) return;
    }
}

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
    vector<bool> vis(n + 1, false);
    vector<int> parent(n + 1, -1);
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            dfs(graph, i, vis, parent);
            if (cycle_start != -1) break;
        }
    }
    if (cycle_start == -1) {
        cout << "IMPOSSIBLE";
        return 0;
    }
    vector<int> path;
    path.push_back(cycle_start);
    for (int v = cycle_end; v != cycle_start; v = parent[v]) path.push_back(v);
    path.push_back(cycle_start);
    reverse(path.begin(), path.end());
    cout << path.size() << "\n";
    for (int x : path) cout << x << " ";
}