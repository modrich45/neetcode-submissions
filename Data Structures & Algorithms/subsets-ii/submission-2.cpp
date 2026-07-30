class Solution {
public:
    vector<vector<int>> res;
    void solve(vector<int>& nums, int i, int n, vector<int>& temp) {
        res.push_back(temp);

        for (int j = i; j < n; j++) {
            if (j > i && nums[j] == nums[j - 1])
                continue;
            temp.push_back(nums[j]);
            solve(nums, j + 1, n, temp);
            temp.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> temp;
        int n = nums.size();
        solve(nums, 0, n, temp);

        return res;
    }
};