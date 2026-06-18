class Solution {
   public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // for rows
        for (int i = 0; i < 9; i++) {
            unordered_set<char> s;
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.') {
                    if (s.count(board[i][j]) != 0) {
                        return false;
                    }
                    s.insert(board[i][j]);
                }
            }
        }
        // for coulumns
        for (int j = 0; j < 9; j++) {
            unordered_set<char> s;
            for (int i = 0; i < 9; i++) {
                if (board[i][j] != '.') {
                    if (s.count(board[i][j]) != 0) {
                        return false;
                    }
                    s.insert(board[i][j]);
                }
            }
        }
        // for boxes
        int si = 0, sj = 0;
        while (si < 9) {
            sj = 0;
            while (sj < 9) {
                unordered_set<char> s;
                for (int i = si; i < si + 3; i++) {
                    for (int j = sj; j < sj + 3; j++) {
                        if (board[i][j] != '.') {
                            if (s.count(board[i][j]) != 0) {
                                return false;
                            }
                            s.insert(board[i][j]);
                        }
                    }
                }
                sj+=3;
            }
            si+=3;
        }
        return true;
    }
};
