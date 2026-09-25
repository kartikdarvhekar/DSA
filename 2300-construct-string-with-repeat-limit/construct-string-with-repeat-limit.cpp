class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        unordered_map<char,int>mp;
        string ans="";
        for(int i=0;i<s.size();i++){
            mp[s[i]]++;
        }
        priority_queue< pair<char,int> >pq;
        for(auto ele:mp){
            pq.push({ele.first,ele.second});

        }
        while(pq.size()>0){
            if(pq.top().second <= repeatLimit){
                for(int i=0;i<pq.top().second;i++){
                    ans+=pq.top().first;
                }
                pq.pop();
            }
            else{
                for(int i=0;i<repeatLimit;i++){
                    ans+=pq.top().first;
                }
                char ch=pq.top().first;
                int freq=pq.top().second-repeatLimit;
                pq.pop();
                if(pq.size()!=0 && pq.top().second>1){
                    ans+=pq.top().first;
                    char ch2=pq.top().first;
                    int freq2=pq.top().second-1;
                    pq.pop();
                    pq.push({ch,freq});
                    pq.push({ch2,freq2});

                }
                else if(pq.size()>0){
                    ans+=pq.top().first;
                    pq.pop();
                    pq.push({ch,freq});
                }
            }

        }
        return ans;

    }
};