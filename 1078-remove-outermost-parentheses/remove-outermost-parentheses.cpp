class Solution {
public:
    string removeOuterParentheses(string s) {
        stack< pair<char,int> >st;
        for(int i=0;i<s.size();i++){
            if(s[i]=='(') st.push({s[i],i});
            if(s[i]==')' && st.size()!=0){
                if(st.size()>1) st.pop();
                else{
                    s[i]='*';
                    s[st.top().second]='*';
                    st.pop();
                }
            }
        }
        string ans="";
        for(int i=0;i<s.size();i++){
            if(s[i]!='*') ans+=s[i];
        }
        return ans;
    }
};