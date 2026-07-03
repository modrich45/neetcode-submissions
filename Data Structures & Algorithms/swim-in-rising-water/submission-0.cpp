class Solution {
public:
    int n;
    vector<vector<int>> dir = {{0,1},{0,-1},{1,0},{-1,0}};

    bool canReach(vector<vector<int>>& grid, int t) {
        if (grid[0][0] > t || grid[n-1][n-1] > t) return false;

        vector<vector<int>> vis(n, vector<int>(n, 0));
        queue<pair<int,int>> q;
        q.push({0, 0});
        vis[0][0] = 1;

        while (!q.empty()) {
            auto [i, j] = q.front(); q.pop();
            if (i == n-1 && j == n-1) return true;

            for (auto& d : dir) {
                int ni = i + d[0], nj = j + d[1];
                if (ni >= 0 && nj >= 0 && ni < n && nj < n 
                    && !vis[ni][nj] && grid[ni][nj] <= t) {
                    vis[ni][nj] = 1;
                    q.push({ni, nj});
                }
            }
        }
        return false;
    }

    int swimInWater(vector<vector<int>>& grid) {
        n = grid.size();
        int lo = 0, hi = n * n - 1; 
        int ans = hi;

        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (canReach(grid, mid)) {
                ans = mid;
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        return ans;
    }
};