#include <bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>>& graph, vector<bool>& vis, int node) {
    vis[node] = true;
    for (auto neigh : graph[node]) {
        if (!vis[neigh]) {
            dfs(graph, vis, neigh);         
        }
    }
    return;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> graph(n + 1);
    for (int i = 1; i <= m; i++) {
        int x, y;
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    vector<bool> vis(n + 1, false);
    vector<int> a;
    for (int node = 1; node <= n; node++) {
        if (!vis[node]) {
            a.push_back(node);
            dfs(graph, vis, node);
        }
    }
    cout << a.size() - 1 << '\n';
    for (int i = 1; i < a.size(); i++) {
        cout << a[i - 1] <<  " " << a[i] << '\n';
    }
    return 0;
}