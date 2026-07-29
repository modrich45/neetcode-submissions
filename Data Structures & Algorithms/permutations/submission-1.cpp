class Solution {
public:
    vector<vector<int>> res;
    void solve(vector<int>& nums, int n, vector<int>& temp, vector<int>& vis) {
        if (temp.size() == n) {
            vector<int> t = temp;
            res.push_back(t);
            return;
        }

        for (int i = 0; i < n; i++) {
           
            if (vis[i] == 0) {
                temp.push_back(nums[i]);
                vis[i] = 1;
                solve(nums, n, temp, vis);
                vis[i] = 0;
                temp.pop_back();
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        vector<int> temp, vis(n, 0);
        solve(nums, n, temp, vis);
        return res;
    }
};
