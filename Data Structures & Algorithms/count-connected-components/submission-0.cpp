class Solution {
public:
    void solve(int i,vector<vector<int>>&adj,vector<int>&vis){
        vis[i]=1;

        for(int &v:adj[i]){
            if(vis[v]==0){
                solve(v,adj,vis);
            }
        }
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        int x=edges.size();
        int y=edges[0].size();
        vector<vector<int>>adj(n);
        vector<int>vis(n,0);
        for(int i=0;i<x;i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        int ans=0;
        for(int i=0;i<n;i++){
            if(vis[i]==0){
                ans++;
                solve(i,adj,vis);
            }
        }
        return ans;
    }
};
