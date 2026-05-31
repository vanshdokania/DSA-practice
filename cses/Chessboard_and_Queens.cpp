#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int ans;

bool isSafe(vector<string>& board, int row, int col) {
    // column check
    for (int i = 0; i < row; i++) { 
        if (board[i][col] == 'Q') return false;
    }
    // left diagonal check
    for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 'Q') return false;
    }
    // right diagonal check
    for (int i = row - 1, j = col + 1; i >= 0 && j <= 7; i--, j++) {
        if (board[i][j] == 'Q') return false;
    }
    return true;
}

void f(vector<string>& board, int row) {
    if (row == 8) {
        ans++;
        return;
    }
    for (int col = 0; col < 8; col++) {
        if (board[row][col] == '*') continue;
        if (!isSafe(board, row, col)) continue;
        board[row][col] = 'Q';
        f(board, row + 1);
        board[row][col] = '.';
    }
    return;
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    vector<string> board(8);
    for (int i = 0; i < 8; i++) cin >> board[i];
    ans = 0;
    f(board, 0);
    cout << ans;
    return 0;
}