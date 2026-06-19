class Solution {
   public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int> m;
        int ans = 0;
        for (int x : nums) {
            if (m.count(x)) continue;
            int left = m.count(x - 1) ? m[x - 1] : 0;
            int right = m.count(x + 1) ? m[x + 1] : 0;
            int len = left + right + 1;
            m[x] = len;
            m[x - left] = len;
            m[x + right] = len;
            ans = max(ans, len);
        }
        return ans;
    }
};
