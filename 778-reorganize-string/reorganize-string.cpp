class Solution {
public:
    string reorganizeString(string s) {
        int n=s.size();
        string ans;
        if(n==0) return "";
        if(n==1) return s;
        priority_queue<pair<int,char>>pq;
        unordered_map<char,int>m;
        for(int i=0;i<n;i++){
            m[s[i]]++;
        }
        for(auto ele : m){
            int freq=ele.second;
            char a=ele.first;
            pq.push({freq,a});
        }
        if((n%2==0) && (pq.top().first>n/2)){
            return "";
        }
        if((n%2!=0) && (pq.top().first>(n/2)+1)) return "";
        while(pq.size()>0){
            char k=pq.top().second;
            int f1=pq.top().first;
            ans+=k;
            pq.pop();
            int f2=0;
            char k2;
            if(pq.size()!=0){
             k2=pq.top().second;
             f2=pq.top().first;
            
            ans+=k2;
             pq.pop();
          }
             f1=f1-1;
             f2=f2-1;
            if(f1>0)pq.push({f1,k});
            if(f2>0)pq.push({f2,k2});
        }
        return ans;
    }
};