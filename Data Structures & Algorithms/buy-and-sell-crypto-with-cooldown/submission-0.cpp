class Solution {
public:
    vector<vector<int>>dp;
    int solve(int i,int prev,int n,vector<int>& prices){
        if(i>=n){
            return 0;
        }

        if(dp[i][prev+1]!=-1){
            return dp[i][prev+1];
        }

        if(prev==-1){
            return dp[i][prev+1]=max(solve(i+1,i,n,prices),solve(i+1,prev,n,prices));
        }else if(prices[i]>prices[prev]){
            return dp[i][prev+1]=max((prices[i]-prices[prev])+solve(i+2,-1,n,prices),solve(i+1,prev,n,prices));
        }else{
            return dp[i][prev+1]=solve(i+1,prev,n,prices);
        }
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        dp.assign(n+1,vector<int>(n+2,-1));
        return solve(0,-1,n,prices);
    }
};
