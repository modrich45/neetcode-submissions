class Solution {
public:
    static bool comp(string& a,string& b){
        return a>b;
    }
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string,vector<string>>adj;
        for(int i=0;i<tickets.size();i++){
            adj[tickets[i][0]].push_back(tickets[i][1]);
        }

        for(auto it=adj.begin();it!=adj.end();it++){
            sort(it->second.begin(),it->second.end(),comp);
        }

        vector<string>path;

        stack<string>st;
        st.push("JFK");
        while(!st.empty()){
            string temp=st.top();
            if(adj.count(temp)!=0 && adj[temp].size()!=0){
                string dest=adj[temp].back();
                st.push(dest);
                adj[temp].pop_back();
            }else{
                path.push_back(temp);
                st.pop();
            }
        }
        reverse(path.begin(),path.end());

        return path;
    }
};
