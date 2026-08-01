class Solution {
public:
    vector<string>res;
    void solve(int ob,int cb,int n,string temp){
        if(ob==n && cb==n){
            res.push_back(temp);
            return;
        }
        if(ob<n){
            temp.push_back('(');
            solve(ob+1,cb,n,temp);
            temp.pop_back();
        }
        if(cb<ob){
            temp.push_back(')');
            solve(ob,cb+1,n,temp);
            temp.pop_back();
        }
        return;
    }
    vector<string> generateParenthesis(int n) {
        solve(0,0,n,"");
        return res;
    }
};
