class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.size()!=goal.size()) return false;
        string k=s;
        k=k+s;
        return k.find(goal)!=string::npos;
        
        }
       
    
};