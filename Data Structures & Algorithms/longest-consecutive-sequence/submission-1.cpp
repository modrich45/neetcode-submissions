class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int>s;
        int n=nums.size();
        for(int i=0;i<n;i++){
            s.insert(nums[i]);
        }
        if(s.empty()) return 0;
        int ans=0;
        int curr=0;
        for(auto it=s.begin();it!=prev(s.end());it++){
            if((*(it) +1) == *(next(it))){
                curr++;
            }else{
                ans=max(ans,curr);
                curr=0;
            }
        }
        ans=max(ans,curr);
        return ans+1;
    }
};
