class Solution {
   public:
   vector<vector<int>>dp;
    int solve(int i, int j, int n, int m, string& word1, string& word2) {
        if(i==n){
            return m-j;
        }
        if(j==m){
            return n-i;
        }
        if(dp[i][j]!=-1) return dp[i][j];
        if (word1[i] == word2[j]) {
            return dp[i][j]=solve(i + 1, j + 1, n, m, word1, word2);
        } else {
            return dp[i][j]=min({1 + solve(i + 1, j, n, m, word1, word2),
                       1 + solve(i, j + 1, n, m, word1, word2),
                       1 + solve(i + 1, j + 1, n, m, word1, word2)});
        }
    }
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        dp.assign(n+1,vector<int>(m+1,-1));
        return solve(0,0,n,m,word1,word2);
    }
};
