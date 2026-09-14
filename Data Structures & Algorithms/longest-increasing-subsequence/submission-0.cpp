class Solution {
public:
    int n;
    vector<vector<int>>dp;
    int solve(vector<int>& nums,int i,int prevIdx,vector<vector<int>>&dp){
        if(i>=n){
            return 0;
        }
        if(dp[i][prevIdx]!=-1) return dp[i][prevIdx];
        if(prevIdx==n+1 || nums[i]>nums[prevIdx]){
            return dp[i][prevIdx]=max(1+solve(nums,i+1,i,dp),solve(nums,i+1,prevIdx,dp));
        }else{
            return dp[i][prevIdx]=solve(nums,i+1,prevIdx,dp);
        }

    }
    int lengthOfLIS(vector<int>& nums) {
        n=nums.size();
        dp.assign(n+2,vector<int>(n+2,-1));
        return solve(nums,0,n+1,dp);
    }
};
