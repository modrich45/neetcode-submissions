class Solution {
public:
    int characterReplacement(string s, int k) {
        int n=s.size();
        int ans=0;
        for(char c='A';c<='Z';c++){
            int cnt=k;
            int i=0,j=0;
            while(i<n && j<n){
                if(s[j]!=c){
                    if(cnt<=0){
                        ans=max(ans,j-i);
                        while(i<n && s[i]==c){
                            i++;
                        }
                        i++;
                    }else{
                        cnt--;
                    }
                }
                j++;
            }
            ans=max(ans,j-i);
        }
        return ans;
    }
};
