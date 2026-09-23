class Solution {
public:
    string frequencySort(string s) {
        priority_queue< pair<int,char> >pq;
        unordered_map<char,int>mp;
        for(int i=0;i<s.size();i++){
            mp[s[i]]++;
        }
        string ans="";
        for(auto ele : mp){
            pq.push({ele.second,ele.first});
        }
        while(pq.size()!=0){
            for(int i=0;i<pq.top().first;i++){
                ans+=pq.top().second;
            }
            pq.pop();
        }
        return ans;
    }
};