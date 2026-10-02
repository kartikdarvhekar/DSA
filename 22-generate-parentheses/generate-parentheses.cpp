class Solution {
public:
    void helper(int n,vector<string>&finalans,string ans,int ob,int cb,int idx){
        if(cb==n){
            finalans.push_back(ans);
            return;
        }
        if(ob<n){
            helper(n,finalans,ans+'(',ob+1,cb,idx);
        }
        if(cb<ob) helper(n,finalans,ans+')',ob,cb+1,idx);
    }
    vector<string> generateParenthesis(int n) {
      
        vector<string>finalans;
        helper(n,finalans,"",0,0,0);
        return finalans;
        
    }
};