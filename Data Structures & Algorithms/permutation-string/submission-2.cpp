class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n1=s1.size();
        int n2=s2.size();

        unordered_map<int,int>m1,m2;
        for(int i=0;i<n1;i++){
            m1[s1[i]]++;
        }
        int i=0,j=0;
        while(j<n2){
            if(j-i+1<n1){
                if(m1.count(s2[j])){
                    m1[s2[j]]--;
                    if(m1[s2[j]]==0){
                        m1.erase(s2[j]);
                    }
                }else{
                    m2[s2[j]]++;
                }
            }else if(j-i+1==n1){
                if(m1.count(s2[j])){
                    m1[s2[j]]--;
                    if(m1[s2[j]]==0){
                        m1.erase(s2[j]);
                    }
                }else{
                    m2[s2[j]]++;
                }
                if(m2.size()==0 && m1.size()==0){
                    return true;
                }
                if(m2.count(s2[i])){
                    m2[s2[i]]--;
                    if(m2[s2[i]]==0){
                        m2.erase(s2[i]);
                    }
                }else{
                    m1[s2[i]]++;
                }
                i++;
            }
            j++;
        }
        return false;
    }
};
