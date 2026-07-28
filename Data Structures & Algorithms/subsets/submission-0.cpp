class Solution {
   public:
    vector<vector<int>> ans;
    void solve(vector<int>& nums, int i, vector<int> temp, int& n) {
        if (i >= n) {
            ans.push_back(temp);
            return;
        }

        solve(nums, i + 1, temp, n);

        temp.push_back(nums[i]);
        solve(nums, i + 1, temp, n);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<int> temp;
        solve(nums, 0, temp, n);
        
        return ans;
    }
};
