class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n=numCourses;
        vector<int>indegree(n);
        vector<vector<int>>adj(n);
        for(int i=0;i<prerequisites.size();i++){
            indegree[prerequisites[i][0]]++;
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        queue<int>q;
        vector<int>res;
        for(int i=0;i<n;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int top=q.front();
            q.pop();
            res.push_back(top);
            for(int v:adj[top]){
                indegree[v]--;
                if(indegree[v]==0){
                    q.push(v);
                }
            }
        }
        if(res.size()==n) return true;
        return false;
    }
};
