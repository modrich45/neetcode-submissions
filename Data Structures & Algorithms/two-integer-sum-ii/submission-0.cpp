class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n=numbers.size();
        unordered_map<int,int>m;
        vector<int>ans;
        for(int i=0;i<n;i++){
            if(m.count(target-numbers[i])){
                ans.push_back(m[target-numbers[i]]);
                ans.push_back(i+1);
            }
            m[numbers[i]]=i+1;
        }
        return ans;
    }
};
