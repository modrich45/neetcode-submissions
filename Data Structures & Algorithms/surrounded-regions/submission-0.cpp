class Solution {
   public:
    int n, m;
    vector<vector<int>> dir = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
    void dfs(vector<vector<char>>& board, int i, int j) {
        if (i < 0 || j < 0 || i >= n || j >= m || board[i][j] == 'X' || board[i][j] == '1') {
            return;
        }
        board[i][j] = '1';
        for (int k = 0; k < 4; k++) {
            int ni = i + dir[k][0];
            int nj = j + dir[k][1];
            dfs(board, ni, nj);
        }
    }
    void solve(vector<vector<char>>& board) {
        n = board.size();
        m = board[0].size();
        for (int i = 0; i < n; i++) dfs(board, i, 0);
        for (int j = 0; j < m; j++) dfs(board, 0, j);
        for (int i = 0; i < n; i++) dfs(board, i, m - 1);
        for (int j = 0; j < m; j++) dfs(board, n - 1, j);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == '1') {
                    board[i][j] = 'O';
                } else {
                    board[i][j] = 'X';
                }
            }
        }
    }
};
