class Solution {
public:

    string encode(vector<string>& strs) {
        string res="";
        int n=strs.size();
        for(int i=0;i<n;i++){
            res+=(to_string(strs[i].size())+"#"+strs[i]);
        }
        return res;
    }

    vector<string> decode(string s) {
        vector<string>ans;
        int n=s.size();
        int i=0;
        while(i<n){
            string curr="";
            while(s[i]!='#'){
                curr+=s[i];
                i++;
            }
            i++;
            int size=stoi(curr);
            curr="";
            for(int j=i;j<i+size && j<n ;j++){
                curr+=s[j];
            }
            ans.push_back(curr);
            i+=size;
        }
        return ans;
    }
};
