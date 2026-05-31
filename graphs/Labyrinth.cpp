#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<char>> grid(n, vector<char>(m));
    vector<vector<char>> parent(n, vector<char>(m));
    vector<vector<bool>> vis(n, vector<bool>(m, false));
    vector<pair<int, int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    vector<char> cdir = {'D', 'U', 'R', 'L'};
    int xa, xb, ya, yb;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
            if (grid[i][j] == 'A') {
                xa = i;
                ya = j;
            }
            else if (grid[i][j] == 'B') {
                xb = i;
                yb = j;
            }
        }
    }
    bool ans = false;
    queue<pair<int, int>> q;
    q.push({xa, ya});
    vis[xa][ya] = true;
    while (!q.empty()) {
        pair<int, int> curr = q.front();
        int x = curr.first;
        int y = curr.second;
        if (x == xb && y == yb) {
            ans = true;
            break;
        }
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = x + dir[i].first;
            int ny = y + dir[i].second;
            if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
                if (grid[nx][ny] != '#' && !vis[nx][ny]) {
                    q.push({nx, ny});
                    vis[nx][ny] = true;
                    parent[nx][ny] = cdir[i];
                } 
            }
        }
    }
    if (ans) {
        cout << "YES\n";
        string path = "";
        int x = xb;
        int y = yb;
        while(x != xa || y != ya){
            char c = parent[x][y];
            path.push_back(c);
            if(c == 'D') x--;
            if(c == 'U') x++;
            if(c == 'R') y--;
            if(c == 'L') y++;
        }
        reverse(path.begin(),path.end());
        cout<<path.size()<<"\n";
        cout<<path<<"\n";
    }
    else cout << "NO";
    return 0;
}