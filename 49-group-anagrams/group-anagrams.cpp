class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>>ans;
        unordered_map<string,vector<string>>mp;
        for(string ele : strs){
            string lexo=ele;
            sort(lexo.begin(),lexo.end());
            if(mp.find(lexo)==mp.end()){
                vector<string>v;
                v.push_back(ele);
                mp[lexo]=v;
            }
            else{
                mp[lexo].push_back(ele);
            }
        }
        for(auto ele :mp){
            ans.push_back(ele.second);
        }
        return ans;
    }
};