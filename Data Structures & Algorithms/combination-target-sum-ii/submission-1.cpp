class Solution {
public:
    vector<vector<int>> res;

    void solve(vector<int>& candidates, int curr, int target, int i, vector<int>& temp) {
        if (curr == target) {
            res.push_back(temp);
            return;
        }

        if (curr > target) {
            return;
        }

        for (int j = i; j < candidates.size(); j++) {
            if (j > i && candidates[j] == candidates[j - 1]) {
                continue;
            }

            temp.push_back(candidates[j]);
            solve(candidates, curr + candidates[j], target, j + 1, temp);
            temp.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());

        vector<int> temp;
        solve(candidates, 0, target, 0, temp);

        return res;
    }
};