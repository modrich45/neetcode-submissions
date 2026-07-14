class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n=temperatures.size();
        vector<int>res(n,0);
        stack<pair<int,int>>st;

        for(int i=0;i<n;i++){
            int t=temperatures[i];
            while(!st.empty() && t>st.top().first){
                res[st.top().second]=i-st.top().second;
                st.pop();
            }
            st.push({t,i});
        }

        return res;
    }
};
