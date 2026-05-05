class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size()) return false;
        unordered_map<char,int>m;
        int n=s.size();
        for(int i=0;i<n;i++){
            m[s[i]]++;
        }
        for(int i=0;i<t.size();i++){
            char ch=t[i];
            if(m.find(ch)!=m.end()){
                m[ch]--;
                if(m[ch]==0) m.erase(ch) ;
            }
            else{
                return false;
            }
        }
        if(m.size()>0) return false;
        return true;
        
    }
};