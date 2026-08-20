class Solution {
   public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int> res(n + 1, INT_MAX);
        vector<vector<pair<int, int>>> adj(n + 1);

        for (int i = 0; i < times.size(); i++) {
            adj[times[i][0]].push_back({times[i][1], times[i][2]});
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
        res[k] = 0;
        q.push({0, k});

        while (!q.empty()) {
            int dist = q.top().first;
            int node = q.top().second;
            q.pop();

            for (auto& v : adj[node]) {
                int dest = v.first;
                int d = v.second;
                if (res[dest] > dist + d) {
                    res[dest] = dist + d;
                    q.push({d + dist, dest});
                }
            }
        }

        int ans = INT_MIN;

        for (int i = 1; i <= n; i++) {
            ans = max(res[i], ans);
        }

        if (ans == INT_MAX) {
            return -1;
        }

        return ans;
    }
};