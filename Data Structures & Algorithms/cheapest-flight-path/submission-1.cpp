typedef pair<int,int> pii;

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights,
                          int src, int dst, int k) {

        vector<vector<pii>> adj(n);

        for (int i = 0; i < flights.size(); i++) {
            adj[flights[i][0]].push_back(
                {flights[i][1], flights[i][2]}
            );
        }

        vector<int> res(n, INT_MAX);
        res[src] = 0;

        queue<pii> pq;

        pq.push({0, src});

        int stop = 0;

        while (stop <= k  && !pq.empty()) {

            int size = pq.size();

            for (int i = 0; i < size; i++) {

                int dist = pq.front().first;  
                int node = pq.front().second; 

                pq.pop();

                for (auto &v : adj[node]) {

                    int neighbour = v.first;
                    int price = v.second;

                    if (res[neighbour] > price + dist) {
                        res[neighbour] = price + dist;
                        pq.push({price + dist, neighbour});
                    }
                }
            }

            stop++;
        }

        if (res[dst] == INT_MAX)
            return -1;

        return res[dst];
    }
};