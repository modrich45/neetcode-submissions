class Solution {
public:
    vector<vector<int>>dp;
    bool solve(int i,int j,int n,string& s,unordered_set<string>& words){
        
        if(j==n-1 && words.find(s.substr(i))!=words.end()){
            return true;
        }
        if(i>=n || j>=n){
            return false;
        }
        if(dp[i][j]!=-1) return dp[i][j];
        if(words.find(s.substr(i,j-i+1))!=words.end()){
            return dp[i][j]=solve(j+1,j+1,n,s,words) || solve(i,j+1,n,s,words);
        }else{
            return dp[i][j]=solve(i,j+1,n,s,words);
        }
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string>words;
        int n=s.size();
        dp.assign(n+2,vector<int>(n+2,-1));
        for(int i=0;i<wordDict.size();i++){
            words.insert(wordDict[i]);
        }

        return solve(0,0,s.size(),s,words);
    }
};
