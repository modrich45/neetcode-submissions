class Solution {
public:
    int n,m;
    vector<vector<vector<int>>>dp;
    bool solve(int i,int j,int k,string& s1,string& s2,string &s3){
        
        if(i>=n){
            while(j<m){
                if(s2[j]==s3[k]){
                    j++;k++;
                }else{
                    return false;
                }
            }
            return true;
        }
        if(j>=m){
            while(i<n){
                if(s1[i]==s3[k]){
                    i++;k++;
                }else{
                    return false;
                }
            }
            return true;
        }
        if(dp[i][j][k]!=-1) return dp[i][j][k];
        if(s1[i]==s3[k] && s2[j]==s3[k]){
            return dp[i][j][k]=solve(i+1,j,k+1,s1,s2,s3) || solve(i,j+1,k+1,s1,s2,s3);
        }else if(s1[i]==s3[k]){
            return dp[i][j][k]=solve(i+1,j,k+1,s1,s2,s3);
        }else if(s2[j]==s3[k]){
            return dp[i][j][k]=solve(i,j+1,k+1,s1,s2,s3);
        }else{
            return false;
        }
    }
    bool isInterleave(string s1, string s2, string s3) {
        n=s1.size();
        m=s2.size();
        dp.assign(n+2,vector<vector<int>>(m+2,vector<int>(n+m+2,-1)));
        if(n+m!=s3.size()) return false;
        return solve(0,0,0,s1,s2,s3);
    }
};
