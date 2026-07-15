class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> nxt(n, n), prev(n, -1);
        vector<pair<int, int>> v;
        for (int i = 0; i < n; i++) {
            v.push_back({heights[i], i});
        }
        stack<pair<int, int>> st;
        for (int i = 0; i < n; i++) {
            while (!st.empty() && heights[i] < st.top().first) {
                nxt[st.top().second] = i;
                st.pop();
            }
            st.push({heights[i], i});
        }
        while (!st.empty()) {
            st.pop();
        }
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && heights[i] < st.top().first) {
                prev[st.top().second] = i;
                st.pop();
            }
            st.push({heights[i], i});
        }
        int ans = INT_MIN;
        for (int i = 0; i < n; i++) {
            ans = max(ans, (nxt[i] - prev[i] - 1) * (heights[i]));
        }
        return ans;
    }
};
