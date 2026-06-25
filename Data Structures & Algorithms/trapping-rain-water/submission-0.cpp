class Solution {
public:
    int trap(vector<int>& nums) {
        int n=nums.size();

        vector<int>pre(n);
        for(int i=0;i<n;i++){
            if(i==0){
                pre[0]=nums[0];
            }else{
                pre[i]=max(pre[i-1],nums[i]);
            }
        }

        vector<int>suff(n);
        for(int i=n-1;i>=0;i--){
            if(i==n-1){
                suff[i]=nums[i];
            }else{
                suff[i]=max(suff[i+1],nums[i]);
            }
        }

        int ans=0;
        for(int i=0;i<n;i++){
            ans+=(min(pre[i],suff[i])-nums[i]);
        }
        return ans;
    }
};
