class Solution {
public:
   int longestValidParentheses(string s) {
    stack<int> st;
    st.push(-1); // Base for the first valid sequence
    int max_len = 0;
    
    for(int i = 0; i < s.size(); i++) {
        if(s[i] == '(') {
            st.push(i);
        } else {
            st.pop();
            if(st.empty()) {
                // This ')' is invalid, it becomes the new base
                st.push(i);
            } else {
                // The current length is the difference between current index 
                // and the last invalid index (or base)
                max_len = max(max_len, i - st.top());
            }
        }
    }
    return max_len;
}
};