class Solution {
public:
    int n;
    vector<vector<int>> dp;

    int solve(int i, vector<int>& nums, int sum, int required) {
        if (i >= n) {
            return sum == required;
        }

        if (dp[i][sum] != -1)
            return dp[i][sum];

        if (sum + nums[i] > required) {
            return dp[i][sum] =
                solve(i + 1, nums, sum, required);
        }

        return dp[i][sum] =
            solve(i + 1, nums, sum, required) +
            solve(i + 1, nums, sum + nums[i], required);
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        n = nums.size();

        int total = accumulate(nums.begin(), nums.end(), 0);

        if (abs(target) > total)
            return 0;

        if ((total + target) % 2 != 0)
            return 0;

        int req = (total + target) / 2;

        dp.assign(n, vector<int>(req + 1, -1));

        return solve(0, nums, 0, req);
    }
};