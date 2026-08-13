class Solution {
public:
    bool isValid(string s) {
        if(s.size()%2!=0) return false;
        unordered_map<char,int>mp;
        int n=s.size();

        for(int i=0;i<n;i++){
            mp[s[i]]++;
        }

        if(mp['(']!=mp[')']) return false;
        if(mp['{']!=mp['}']) return false;
        if(mp['[']!=mp[']']) return false;
        stack<char>st;
        for(int i=0;i<n;i++){
            if((s[i]==')' || s[i]=='}' || s[i]==']')&& st.size()==0) return false;
            if(s[i]==')'){
                if(st.top()=='(') st.pop();

                continue;
            }
             if(s[i]=='}'){
                if(st.top()=='{') st.pop();
                continue;
            }
             if(s[i]==']'){
                if(st.top()=='[') st.pop();
                continue;
            }
            st.push(s[i]);

            
        }
       if(st.size()!=0) return false;
        return true; 
    }
};