class Solution {
   public:
    void dfs(vector<vector<int>>& A, vector<vector<int>>& vis, int i, int j,
             vector<vector<int>>& dir, int n, int m, int prevHeight) {
        if (i < 0 || i >= n || j < 0 || j >= m) return;
        if (vis[i][j]) return;
        if (A[i][j] < prevHeight) return;

        vis[i][j] = 1;

        for (int d = 0; d < 4; d++) {
            int nx = i + dir[d][0];
            int ny = j + dir[d][1];
            dfs(A, vis, nx, ny, dir, n, m, A[i][j]);
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& A) {
        
        int n = A.size(), m = A[0].size();
        vector<vector<int>>ans;
        vector<vector<int>> visb(n, vector<int>(m, 0));
        vector<vector<int>> visr(n, vector<int>(m, 0));
        vector<vector<int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        for (int i = 0; i < n; i++) dfs(A, visb, i, 0, dir, n, m, A[i][0]);
        for (int j = 0; j < m; j++) dfs(A, visb, 0, j, dir, n, m, A[0][j]);
        for (int i = 0; i < n; i++) dfs(A, visr, i, m - 1, dir, n, m, A[i][m - 1]);
        for (int j = 0; j < m; j++) dfs(A, visr, n - 1, j, dir, n, m, A[n - 1][j]);

        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (visb[i][j] && visr[i][j]) ans.push_back({i,j});

        return ans;
    }
};
