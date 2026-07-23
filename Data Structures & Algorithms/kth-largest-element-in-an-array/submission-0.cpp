class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        multiset<int>ms;
        int n=nums.size();

        for(int i=0;i<n;i++){

            ms.insert(nums[i]);
            if(ms.size()>k){
                ms.erase(ms.begin());
            }
        }
        return *ms.begin();
    }
};
