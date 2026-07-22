class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int>mh;

        for(int &x: stones){
            mh.push(x);
        }

        while(mh.size()>1){
            int f=mh.top();
            mh.pop();
            int s=mh.top();
            mh.pop();

            if(f>s){
                mh.push(f-s);
            }
        }

        if(mh.size()==1){
            return mh.top();
        }
        return 0;
    }
};
