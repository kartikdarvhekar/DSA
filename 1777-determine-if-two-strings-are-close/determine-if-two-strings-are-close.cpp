class Solution {
public:
    bool closeStrings(string str1, string str2) {
        if(str1.size()!=str2.size()) return false;
        int n=str1.size();
        unordered_map<char,int>mp1;
        unordered_map<char,int>mp2;
        for(int i=0;i<n;i++){
            mp1[str1[i]]++;
            mp2[str2[i]]++;
        }
        vector<int>v1;
        vector<int>v2;
        
        
       
        for(auto ele:mp1){
            if(mp2.find(ele.first)==mp2.end()){
                return false;
            }
            v1.push_back(ele.second);
        }
        
            for(auto ele:mp2){
            
            v2.push_back(ele.second);
        }
        sort(v2.begin(),v2.end());
        sort(v1.begin(),v1.end());
        return v1==v2;
        
    }
};