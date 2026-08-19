class Solution {
public:
    int start = -1, end = -1;

    bool dfs(vector<vector<int>>& adj, int i, vector<int>& parent, int par) {
        parent[i] = par;

        for (int& v : adj[i]) {
            if (v == par) {
                continue;
            }

            if (parent[v] != 0) {
                start = i;
                end = v;
                return true;
            }

            if (dfs(adj, v, parent, i)) {
                return true;
            }
        }

        return false;
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();

        vector<vector<int>> adj(n + 1);
        vector<int> parent(n + 1, 0);

        for (int i = 0; i < n; i++) {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }

        if (!dfs(adj, 1, parent, -1)) {
            return {};
        }

        set<int> temp;

        while (parent[start] != end) {
            temp.insert(start);
            start = parent[start];
        }

        temp.insert(start);
        temp.insert(end);

        vector<int> ans;

        for (int i = 0; i < n; i++) {
            if (temp.count(edges[i][0]) != 0 &&
                temp.count(edges[i][1]) != 0) {
                ans = edges[i];
            }
        }

        return ans;
    }
};