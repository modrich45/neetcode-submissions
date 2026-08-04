class Solution {
public:
    vector<vector<int>>dir={{0,1},{0,-1},{1,0},{-1,0}};
    void solve(vector<vector<char>>& grid,int n,int m,int i,int j){
        if(i<0 || j<0 || i>=n || j>=m || grid[i][j]=='0') return ;
        grid[i][j]='0';

        for(int k=0;k<4;k++){
            int ni=i+dir[k][0];
            int nj=j+dir[k][1];

            solve(grid,n,m,ni,nj);
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1'){
                    ans++;
                    solve(grid,n,m,i,j);
                }
            }
        }
        return ans;
    }
};
