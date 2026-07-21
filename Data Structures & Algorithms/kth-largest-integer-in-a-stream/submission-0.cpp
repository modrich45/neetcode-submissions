class KthLargest {
public:

    multiset<int>ms;
    int x;
    KthLargest(int k, vector<int>& nums) {
        x=k;
        for(int i=0;i<nums.size();i++){
            ms.insert(nums[i]);
        }
    }
    
    int add(int val) {
        ms.insert(val);
        while(ms.size()>x){
            ms.erase(ms.begin());
        }
        return *(ms.begin());
    }
};
