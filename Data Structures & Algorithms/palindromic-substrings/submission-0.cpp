class Solution {
public:
    int ans=0;
    int n;
    void solve(string &s,int i,int j){
        
        if(i<0 || j>=n || (s[i]!=s[j])){
            return;
        }else{
            ans++;
            solve(s,i-1,j+1);
        }
    }
    int countSubstrings(string s) {
        n=s.size();
        for(int i=0;i<n;i++){
            solve(s,i,i);
            if(i<=n-2){
                solve(s,i,i+1);
            }
        }
        return ans;
    }
};
