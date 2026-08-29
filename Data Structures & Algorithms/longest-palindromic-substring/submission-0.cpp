class Solution {
public:
    string ans;
    int start,len=-1;
    int n;
    void solve(string &s,int i,int j){
        
        if(i<0 || j>=n || (s[i]!=s[j])){
            int currLen=j-i-1;
            if(len<currLen){
                start=i+1;
                len=currLen;
            }
            return;
        }else{
            solve(s,i-1,j+1);
        }
    }
    string longestPalindrome(string s) {
        n=s.size();
        for(int i=0;i<n;i++){
            solve(s,i,i);
            if(i<=n-2){
                solve(s,i,i+1);
            }
        }
        ans=s.substr(start,len);
        return ans;
    }
};
