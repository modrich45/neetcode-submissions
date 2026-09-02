class Solution {
   public:
    int n;
    int solve(int i, string& s,vector<int>&dp) {
        if (i == n) return 1;       
        if (s[i] == '0') return 0;

        if(dp[i]!=-1) return dp[i];

        if ((s[i] == '1' || s[i] == '2') && i < n - 1 && s[i + 1] == '0') {
            int res = solve(i + 2, s,dp);
            return dp[i]=res;              
        }

        if (s[i] == '1' || s[i] == '2') {
            if (s[i] == '2' && !(i < n - 1 && s[i + 1] <= '6' && s[i + 1] >= '0')) {
                int res = solve(i + 1, s,dp);
                return dp[i]=res;          
            }

            int res1 = solve(i + 1, s,dp);                    
            int res2 = (i < n - 1) ? solve(i + 2, s,dp) : 0;    
            return dp[i]=res1 + res2;
        }

        int res = solve(i + 1, s,dp);
        return dp[i]=res;                 
    }
    int numDecodings(string s) {
        n = s.size();
        vector<int>dp(n+1,-1);
        int ans = solve(0, s,dp);
        return ans;                 
    }
};