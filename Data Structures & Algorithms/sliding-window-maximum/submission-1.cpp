class Solution {
   public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        int i = 0, j = 0;
        multiset<int> m;
        vector<int>ans;
        while (j < n) {
            if (j - i + 1 < k) {
                m.insert(nums[j]);
                j++;
            } else if (j - i + 1 == k) {
                m.insert(nums[j]);
                ans.push_back(*m.rbegin());
                auto it=m.find(nums[i]);
                m.erase(it);
                i++;j++;
            }
        }
        return ans;
    }
};
