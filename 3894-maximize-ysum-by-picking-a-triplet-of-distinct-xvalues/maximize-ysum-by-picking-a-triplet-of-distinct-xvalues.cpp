class Solution {
public:
    int maxSumDistinctTriplet(vector<int>& x, vector<int>& y) {
        unordered_map<int,int>mp;
        int n=x.size();
        if(n<=2) return -1;
        mp[x[0]]=0;
        for(int i=1;i<x.size();i++){
            if(mp.find(x[i])!=mp.end()){
                if(y[i]>y[mp[x[i]]]){
                    mp[x[i]]=i;
                }
            }
            else mp[x[i]]=i;
        }
        if(mp.size()<3) return -1;
        priority_queue<int>pq;
        for(auto ele : mp){
            pq.push(y[ele.second]);
        }
        int sum=0;
        for(int i=0;i<3;i++){
            sum+=pq.top();
            pq.pop();
        }
        return sum;
    }
};