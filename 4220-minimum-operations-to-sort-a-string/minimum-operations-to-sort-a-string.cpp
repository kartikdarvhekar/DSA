class Solution {
public:
    int minOperations(string s) {
        string org=s;
        sort(s.begin(),s.end());
        if(s==org) return 0;
        if(org.size()==2) return -1;
        if(s[0]==org[0] || s[s.size()-1]==org[org.size()-1]){
            return 1;
        }
        if(s[0]==org[org.size()-1] && s[s.size()-1]==org[0]){
            for(int i=1;i<s.size()-1;i++){
                if(org[i]==s[0] || org[i]==s[s.size()-1]) return 2;
                
            }
            return 3;

        }
        return 2;


    }
};