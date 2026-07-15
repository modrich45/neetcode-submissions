class Solution {
public:
    static bool comp(pair<int,int>&a , pair<int,int>&b){
        return a.first<b.first;
    }
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n=position.size();
        vector<pair<int,int>>v;
        for(int i=0;i<n;i++){
            v.push_back({position[i],i});
        }
        sort(v.begin(),v.end(),comp);
        int ans=0;
        vector<double>time(n);
        for(int i=0;i<n;i++){
            time[i]=((double)(target-v[i].first) /(double)speed[v[i].second]);
            cout<<time[i]<< " ";
        }


        stack<double>st;

        for(int i=n-1;i>=0;i--){
            while(!st.empty() && time[i]>st.top()){
                st.pop();
                if(st.empty()){
                    ans++;
                }
            }
            
            st.push(time[i]);
        }

        return ans+1;
    }
};
