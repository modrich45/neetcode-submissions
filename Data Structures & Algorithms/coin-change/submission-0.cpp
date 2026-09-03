class Solution {
public:
    int solve(vector<int>& coins, int i, int curr, vector<vector<int>>& dp) {
        if (curr == 0)
            return 0;

        if (i < 0 || curr < 0)
            return INT_MAX;

        if (dp[i][curr] != -1)
            return dp[i][curr];

        int take = solve(coins, i, curr - coins[i], dp);

        if (take != INT_MAX)
            take++;

        int notTake = solve(coins, i - 1, curr, dp);

        return dp[i][curr] = min(take, notTake);
    }

    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();

        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));

        int ans = solve(coins, n - 1, amount, dp);

        return ans == INT_MAX ? -1 : ans;
    }
};