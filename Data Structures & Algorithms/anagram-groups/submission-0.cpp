class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n=strs.size();
        unordered_map<string,vector<string>>m;
        for(int i=0;i<n;i++){
            string temp=strs[i];
            sort(temp.begin(),temp.end());
            m[temp].push_back(strs[i]);
        }
        vector<vector<string>>res;
        for(auto it=m.begin();it!=m.end();it++){
            vector<string>temp;
            for(int i=0;i<it->second.size();i++){
                temp.push_back(it->second[i]);
            }
            res.push_back(temp);
        }
        return res;
    }
};
