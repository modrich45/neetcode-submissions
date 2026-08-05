class Solution {
   public:
    vector<vector<int>> dir = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        queue<pair<int, int>> q;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 2) {
                    q.push({i, j});
                }
            }
        }
        bool flag=true;
        int ans = 0;
        if(q.empty()) flag=false;
        while (!q.empty()) {
            int size = q.size();
            for (int k = 0; k < size; k++) {
                int i = q.front().first;
                int j = q.front().second;
                q.pop();
                for (int d = 0; d < 4; d++) {
                    int ni = i + dir[d][0];
                    int nj = j + dir[d][1];
                    if (ni < 0 || nj < 0 || ni >= n || nj >= m || grid[ni][nj] == 0 ||
                        grid[ni][nj] == 2)
                        continue;
                    q.push({ni, nj});
                    grid[ni][nj] = 2;
                }
            }
            ans++;
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    return -1;
                }
            }
        }
        if(!flag) return 0;
        return ans-1;
    }
};
