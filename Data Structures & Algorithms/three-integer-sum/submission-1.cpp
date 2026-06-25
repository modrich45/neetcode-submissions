class Solution {
public:
    vector<vector<int>> twoSum(vector<int>&nums,int j,int target){
        unordered_set<int>m;
        vector<vector<int>> results;
        int n=nums.size();
        for(int i=j+1;i<n;i++){
            if(m.find(target-nums[i])!=m.end()){
                results.push_back({target-nums[i],nums[i]});
            }
            m.insert(nums[i]);
        }
        return results;
    }
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n=nums.size();
        set<vector<int>>s;
        for(int i=0;i<n;i++){
            int target=-nums[i];
            vector<vector<int>> pairs = twoSum(nums,i,target);
            for(auto& x : pairs){
                vector<int>temp;
                temp.push_back(nums[i]);
                temp.push_back(x[0]);
                temp.push_back(x[1]);

                sort(temp.begin(),temp.end());
                s.insert(temp);
            }
        }
        vector<vector<int>>ans;
        for(auto it=s.begin();it!=s.end();it++){
            ans.push_back((*it));
        }

        return ans;
    }
};
