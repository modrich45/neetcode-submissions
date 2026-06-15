class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        set<int>ms;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]>0){
                ms.insert(nums[i]);
            }
        }
        int res=1;
        for(auto it=ms.begin();it!=ms.end();it++ ){
            if(res==(*it)){
                res++;
            }else{
                break;
            }
        }
        return res;
    }
};