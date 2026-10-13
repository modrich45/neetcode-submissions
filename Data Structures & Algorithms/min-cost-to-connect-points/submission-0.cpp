class Solution {
   public:
    void Union(int x, int y, vector<int>& parent, vector<int>& rank) {
        int x_parent = findParent(x, parent);
        int y_parent = findParent(y, parent);

        if (x_parent == y_parent) {
            return;
        }

        if (rank[x_parent] > rank[y_parent]) {
            parent[y_parent] = x_parent;
        } else if (rank[y_parent] > rank[x_parent]) {
            parent[x_parent] = y_parent;
        } else {
            parent[x_parent] = y_parent;
            rank[y_parent]++;
        }
    }
    int findParent(int x, vector<int>& parent) {
        if (x == parent[x]) {
            return x;
        }
        return parent[x] = findParent(parent[x], parent);
    }
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<vector<int>> temp;
        vector<int>parent(n),rank(n,0);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                temp.push_back(
                    {i, j, abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1])});
            }
        }
        sort(temp.begin(), temp.end(), [](auto& a, auto& b) { return a[2] < b[2]; });
        int ans = 0;
        for (auto& vec : temp) {
            int u = vec[0];
            int v = vec[1];
            int wt = vec[2];

            if (findParent(u, parent) != findParent(v, parent)) {
                Union(u, v, parent, rank);
                ans += wt;
            }
        }
        return ans;
    }
};
