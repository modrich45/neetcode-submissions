class Solution {
public:
    set<vector<int>>ans;
    void solve(vector<int>& nums,int i, int target,int n,int curr,vector<int>temp){
        if(target==curr){
            sort(temp.begin(),temp.end());
            ans.insert(temp);
            return;
        }
        if(i<0) return;

        if(curr<target){
            solve(nums,i-1,target,n,curr,temp);
            temp.push_back(nums[i]);
            solve(nums,i,target,n,curr+nums[i],temp);
            solve(nums,i-1,target,n,curr+nums[i],temp);
        }else{
            return;
        }
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        vector<int>temp;
        solve(nums,nums.size()-1,target,nums.size(),0,temp);
        vector<vector<int>>res;
        for(auto it=ans.begin();it!=ans.end();it++){
            res.push_back((*it));
        }
        return res;
    }
};
