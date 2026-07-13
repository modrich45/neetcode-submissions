class Solution {
   public:
    string minWindow(string s, string t) {
        int n = s.size();
        int m = t.size();
        unordered_set<char> st;
        unordered_map<char, int> m1, m2;
        for (int i = 0; i < m; i++) {
            st.insert(t[i]);
            m1[t[i]]++;
        }
        int ans = INT_MAX;
        int i = 0, j = 0;
        int left = -1, right = -1;
        while (j < n) {
            if (m1.count(s[j])) {
                m1[s[j]]--;
                if (m1[s[j]] == 0) {
                    m1.erase(s[j]);
                }
            } else if (st.count(s[j])) {
                m2[s[j]]++;
            }
            // for(auto it = m1.begin();it!=m1.end();it++){
            //         cout<<it->first << " "<< it->second<<endl;
            // }

            while (m1.size() == 0) {
                if (ans >= (j - i + 1)) {
                    left = i;
                    right = j;
                    ans = (j - i + 1);
                }
                if (st.count(s[i])) {
                    if (m2.count(s[i])) {
                        m2[s[i]]--;
                        if (m2[s[i]] == 0) {
                            m2.erase(s[i]);
                        }
                    } else {
                        m1[s[i]]++;
                    }
                }
                i++;
            }
            j++;
        }
        string res = "";
        if (left == -1 || right == -1) {
            return res;
        }
        for (int x = left; x <= right; x++) {
            res += s[x];
        }
        return res;
    }
};
