class Solution {
public:
    vector<vector<string>>res;
    bool isPalindrome(string &s,int i,int j){
        string temp=s.substr(i,j-i+1);
        int n=temp.size();

        int l=0,r=n-1;
        while(l<=r){
            if(temp[l]!=temp[r]){
                return false;
            }
            l++;r--;
        }
        return true;
    }

    void solve(string &s,int i,int j,int n,vector<string>&temp){
        if(i>=n && j>=n){
            res.push_back(temp);
        }
        if(i>=n || j>=n){
            return;
        }
        if(isPalindrome(s,i,j)){
            temp.push_back(s.substr(i,j-i+1));
            solve(s,j+1,j+1,n,temp);
            temp.pop_back();
        }
        solve(s,i,j+1,n,temp);
    }


    vector<vector<string>> partition(string s) {
        vector<string>temp;
        solve(s,0,0,s.size(),temp);
        return res;
    }
};
