class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        string ans="";
        unordered_map<string,string>mp;
        for(int i=0;i<knowledge.size();i++){
            mp[knowledge[i][0]]=knowledge[i][1];
        }
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                string temp="";
                i++;
                while(s[i]!=')'){
                    temp+=s[i];
                    i++;
                }
                
                bool flag=false;
                
                    if(mp.find(temp)!=mp.end()){
                        ans+=mp[temp];
                       
                        flag=true;
                       
                    }
                
                if(flag==false){
                    ans+='?';
                }
            }
            else{
                ans+=s[i];
            }
        }
        return ans;
    }
};