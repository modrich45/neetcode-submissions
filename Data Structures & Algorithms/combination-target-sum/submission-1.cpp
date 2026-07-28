class Solution {
   public:
    set<vector<int>> ans;
    void solve(vector<int>& nums, int i, int target, int curr, vector<int>& temp) {
        if (curr == target) {
            vector<int> t = temp;
            sort(t.begin(), t.end());
            ans.insert(t);
            return;
        }

        if (i < 0 || curr > target) return;
        solve(nums, i - 1, target, curr, temp);
        temp.push_back(nums[i]);
        solve(nums, i, target, curr + nums[i], temp);
        solve(nums, i - 1, target, curr + nums[i], temp);
        temp.pop_back();
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());

        vector<int> temp;
        solve(nums, nums.size() - 1, target, 0, temp);

        return vector<vector<int>>(ans.begin(), ans.end());
    }
};
