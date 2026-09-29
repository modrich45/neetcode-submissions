class Solution {
public:
    vector<vector<int>>dp;
    int solve(int i,int curr,int amount,vector<int>& coins){
        if(curr==amount){
            return 1;
        }
        if(i<0){
            return 0;
        }
        if(dp[i][curr]!=-1) return dp[i][curr];
        
        if(curr+coins[i]>amount){
            return dp[i][curr]=solve(i-1,curr,amount,coins);
        }else{
            return dp[i][curr]=solve(i,curr+coins[i],amount,coins) + solve(i-1,curr,amount,coins);
        }
    }
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        dp.assign(n+2,vector<int>(amount+10,-1));
        return solve(n-1,0,amount,coins);
    }
};
