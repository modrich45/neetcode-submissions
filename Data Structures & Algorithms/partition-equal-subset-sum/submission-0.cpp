class Solution {
public:
    vector<vector<int>>dp;
    bool solve(int i,int curr,int sum,int n,vector<int>& nums){
        
        if(curr==sum){
            return true;
        }

        if(i>=n){
            return false;
        }

        if(dp[i][curr]!=-1) return dp[i][curr];

        if(curr+nums[i]>sum){
            return dp[i][curr]=solve(i+1,curr,sum,n,nums);
        }else{
            return dp[i][curr]=solve(i+1,curr+nums[i],sum,n,nums) || solve(i+1,curr,sum,n,nums);
        }
    }
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }
        if(sum%2!=0){
            return false;
        }
        dp.assign(n+2,vector<int>(sum+2,-1));
        return solve(0,0,sum/2,n,nums);
    }
};
