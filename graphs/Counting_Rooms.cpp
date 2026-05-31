#include <bits/stdc++.h>
using namespace std;

void bfs(vector<vector<char>>& grid, vector<vector<bool>>& vis, int i, int j) {
    vector<pair<int, int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    queue<pair<int, int>> q;
    q.push({i, j});
    vis[i][j] = true;
    while (!q.empty()) {
        pair<int, int> curr = q.front();
        int x = curr.first;
        int y = curr.second;
        q.pop();
        for (auto d : dir) {
            int nx = x + d.first;
            int ny = y + d.second;
            if (nx >= 0 && nx < grid.size() && ny >= 0 && ny <= grid[0].size()) {
                if (grid[nx][ny] == '.' && !vis[nx][ny]) {
                    q.push({nx, ny});
                    vis[nx][ny] = true;
                }
            }
        }
    }
    return;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<char>> grid(n, vector<char>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }
    vector<vector<bool>> vis(n, vector<bool>(m, false));
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == '.' && !vis[i][j]) {
                ans++;
                bfs(grid, vis, i, j);
            }
        }
    }
    cout << ans;
    return 0;
}