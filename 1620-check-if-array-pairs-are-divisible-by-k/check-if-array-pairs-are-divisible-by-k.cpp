class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        unordered_map<int,int>mp;
        for(auto ele : arr){
            ele=((ele%k)+k)%k;
            mp[ele]++;
        }
        if(mp.find(0)!=mp.end()){
            if(mp[0]%2!=0) return false;
            mp.erase(0);
        }
        for(auto ele :mp){
            int rem=k-ele.first;
            if(mp.find(rem)==mp.end()) return false;
            if(mp[rem]!=mp[ele.first]) return false;
        }
        return true;
    }
};