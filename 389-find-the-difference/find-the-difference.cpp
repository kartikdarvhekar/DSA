class Solution {
public:
    char findTheDifference(string s, string t) {
        int k=0;
        if(s.size()==0 && t.size()==1) return t[0];
        unordered_map<char,int>mp;
        for(int i=0;i<s.size();i++){
            mp[s[i]]++;
        }
        for(int i=0;i<t.size();i++){
            if(mp.size()!=0 &&  mp.find(t[i])!=mp.end() ){
                mp[t[i]]--;
                if(mp[t[i]]==0) mp.erase(t[i]);
            }
            else{
                return t[i];
                k=i;
                break;
            }
        }
        return t[k];
    }
};