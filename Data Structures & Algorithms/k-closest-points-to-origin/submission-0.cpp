class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        multiset<pair<int,pair<int,int>>>ms;
        vector<vector<int>>ans;
        int n=points.size();
        for(int i=0;i<n;i++){
            int x=points[i][0]*points[i][0];
            int y=points[i][1]*points[i][1];
            ms.insert({x+y,{points[i][0],points[i][1]}});
        }
        while(k--){
            pair<int,pair<int,int>>p=*(ms.begin());
            ms.erase(ms.begin());
            ans.push_back({p.second.first,p.second.second});
        }
        return ans;
    }
};
