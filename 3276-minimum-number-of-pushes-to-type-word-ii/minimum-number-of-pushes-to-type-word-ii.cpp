class Solution {
public:
    
    
    int minimumPushes(string s) {
        unordered_map<char,int>mp;
        for(int i=0;i<s.size();i++){
            mp[s[i]]++;// char,int
        }
        int sm=0;
        priority_queue<pair<int,char>>pq;
        for(auto ele:mp){
            int freq=ele.second;
            char j=ele.first;
            pq.push({freq,j});
        }
        int b=1;
        while(pq.size()>0){
            
            for(int i=0;i<8;i++){
               
                sm=sm+(b*(pq.top().first));
                pq.pop();
                 if(pq.size()==0) break;
            }
            b++;
        }
        return sm;


    }
};