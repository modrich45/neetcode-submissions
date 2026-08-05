class Solution {
public:
    vector<vector<int>>dir={{0,1},{0,-1},{1,0},{-1,0}};
    void solve(vector<vector<int>>& grid,vector<vector<int>>&res){
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<int,pair<int,int>>>q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==0){
                    res[i][j]=0;
                    q.push({0,{i,j}});
                }
            }
        }
        while(!q.empty()){
            int dist=q.front().first;
            int i=q.front().second.first;
            int j=q.front().second.second;
            q.pop();
            for(int k=0;k<4;k++){
                int ni=i+dir[k][0];
                int nj=j+dir[k][1];
                if(ni<0 || nj<0 || ni>=n || nj>=m || grid[ni][nj]==-1) continue;
                if(1+dist < res[ni][nj]){
                    res[ni][nj]=1+dist;
                    q.push({1+dist,{ni,nj}});
                }
            }
        }
    }
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>res(n,vector<int>(m,INT_MAX));
        solve(grid,res);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(res[i][j]==INT_MAX){
                    grid[i][j]=-1;
                }else{
                    grid[i][j]=res[i][j];
                }
            }
        }
    }
};
