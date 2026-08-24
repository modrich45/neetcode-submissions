class Solution {
public:

    int solve(vector<int>& cost,int i,int n,vector<int>&dp){
        if(i>=n){
            return 0;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        return dp[i]=cost[i]+min(solve(cost,i+1,n,dp),solve(cost,i+2,n,dp));
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        vector<int>dp(n+2,-1);
        solve(cost,0,n,dp);
        int ans=min(dp[0],dp[1]);
        return ans;
    }
};
