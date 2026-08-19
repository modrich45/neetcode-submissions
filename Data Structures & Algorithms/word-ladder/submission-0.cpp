class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string,int>m;
        m[beginWord]=1;
        for(int i=0;i<wordList.size();i++){
            m[wordList[i]];
        }
        queue<string>q;
        int ans=0;
        q.push(beginWord);
        while(!q.empty()){
            int size=q.size();
            for(int i=0;i<size;i++){
                string curr=q.front();
                q.pop();
                if(curr==endWord){
                    return ans+1;
                }
                for(int j=0;j<curr.size();j++){
                    string temp=curr;
                    for(char c='a';c<='z';c++){
                        temp[j]=c;
                        if(m.count(temp)!=0 && m[temp]==0){
                            m[temp]=1;
                            q.push(temp);
                        }
                    }
                }
            }
            ans++;
        }
        return 0;
    }
};
