class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<char>v1(26,0),v2(26,0);
        int n=s.size();
        int m=t.size();
        if(n!=m) return false;

        for(int i=0;i<n;i++){
            v1[s[i]-'a']++;
            v2[t[i]-'a']++;
        }

        for(int i=0;i<26;i++){
            if(v1[i]!=v2[i]){
                return false;
            }
        }
        return true;
    }
};
