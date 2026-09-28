class Solution {
public:
    int maxDepth(string s) {
        int mx=0;
        stack<char>st;
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                st.push(s[i]);
            }
            if(s[i]==')'){
                int k=st.size();
                mx=max(k,mx);
                st.pop();

            }
        }
        return mx;
    }
};