class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        set<char>st;
        int n=s.size();
        int i=0,j=0;
        int ans=0;
        while(j<n){

            if(st.count(s[j])){
                ans=max(ans,j-i);
                while(s[i]!=s[j]){
                    st.erase(s[i]);
                    i++;
                }
                i++;
            }
            st.insert(s[j]);
            j++;
            
        }
        ans=max(ans,j-i);
        return ans;
    }
};
