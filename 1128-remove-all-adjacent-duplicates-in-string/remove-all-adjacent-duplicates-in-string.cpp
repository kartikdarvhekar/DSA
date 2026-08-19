class Solution {
public:
    string removeDuplicates(string s) {
        stack<char>st;
        int n=s.size();
        if(n!=0) st.push(s[0]);
        for(int i=1;i<s.size();i++){
            if(st.size()!=0 && st.top()==s[i]) st.pop();
            else st.push(s[i]);
        }
        vector<char>ans;
        while(st.size()!=0){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        string arr="";
        for(int i=0;i<ans.size();i++){
            arr+=ans[i];
        }
        return arr;
    
    }
};