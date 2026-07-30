class Solution {
   public:
    vector<vector<int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    bool solve(vector<vector<char>>& board, int i, int j, int idx, string& word,
               vector<vector<int>>& vis) {
        if (idx == word.size()) return true;
        if (i < 0 || j < 0 || i >= board.size() || j >= board[0].size() ||
            board[i][j] != word[idx] || vis[i][j] == 1) {
            return false;
        }
        vis[i][j] = 1;

        bool ans = false;
        for (int k = 0; k < 4; k++) {
            int ni = i + dir[k][0];
            int nj = j + dir[k][1];

            ans |= solve(board, ni, nj, idx + 1, word, vis);
        }
        vis[i][j] = 0;
        return ans;
    }
    bool exist(vector<vector<char>>& board, string word) {
        bool ans = false;
        int n = board.size();
        int m = board[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (board[i][j] == word[0]) {
                    ans |= solve(board, i, j, 0, word, vis);
                }
            }
        }
        return ans;
    }
};
