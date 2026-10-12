class Solution {
public:
    vector<vector<int>>dir={{0,1},{0,-1},{-1,0},{1,0}};
    int solve(int i,int j,int n,int m,vector<vector<int>>& matrix,vector<vector<int>>&dp){
        if(dp[i][j]!=-1) return dp[i][j];
        int temp=0;
        for(int d=0;d<4;d++){
            int ni=i+dir[d][0];
            int nj=j+dir[d][1];

            if(ni>=0 && ni<n && nj>=0 && nj<m && matrix[ni][nj]>matrix[i][j] ){
                temp=max(temp,1+solve(ni,nj,n,m,matrix,dp));
            }
        }
        return dp[i][j]=temp;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(dp[i][j]==-1){
                    ans= max(ans,1+solve(i,j,n,m,matrix,dp));
                }
            }
        }
        return ans;
    }
};
