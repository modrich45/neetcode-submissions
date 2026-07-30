class Solution {
public:
    set<vector<int>>res;
    void solve(vector<int>& nums,int i,int n,vector<int>&temp){
        if(i==n){
            res.insert(temp);
            return;
        }
        int j;
        for(j=i;j<n;j++){
            if(j>i && nums[j]==nums[j-1]) continue;
            temp.push_back(nums[j]);
            solve(nums,j+1,n,temp);
            temp.pop_back();
        }
        if(j==n){
            solve(nums,j,n,temp);
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int>temp;
        int n=nums.size();
        for(int i=0;i<n;i++){
            solve(nums,i,n,temp);
        }
        
        return vector<vector<int>>(res.begin(),res.end());
    }
};