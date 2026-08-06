class Solution {
   public:
    bool isCycle(vector<vector<int>>& adj, vector<int>& vis, int i, int parent) {
        vis[i] = 1;
        for (int& v : adj[i]) {
            if (v == parent) {
                continue;
            }
            if (vis[v] == 1) {
                return true;
            }
            if (isCycle(adj, vis, v, i)) {
                return true;
            }
        }
        return false;
    }
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        vector<int> vis(n, 0);
        for (int i = 0; i < edges.size(); i++) {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (vis[i] == 0) {
                if (isCycle(adj, vis, i, -1)) {
                    return false;
                }
                ans++;
            }
        }
        if (ans > 1) {
            return false;
        }
        return true; 
    }
};
