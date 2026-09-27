class Solution {
public:
    string reverseParentheses(string s) {
        stack<int>st;

        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                st.push(i);
                s[i]='#';
            }
            else if(s[i]==')'){
                reverse(s.begin()+st.top(),s.begin()+i);
                s[i]='#';
                st.pop();
            }
        }
        string ans="";
        for(int i=0;i<s.size();i++){
            if(s[i]!='#'){
            ans+=s[i];
            }
        }
        return ans;
    }
};