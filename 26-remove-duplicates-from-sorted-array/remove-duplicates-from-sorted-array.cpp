class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        unordered_set<int>s;
        for(int i=0;i<nums.size();i++){
            s.insert(nums[i]);
        }
        
        int k= s.size();
        vector<int>v;
        for(auto ele:s){
            v.push_back(ele);
        }
        sort(v.begin(),v.end());
        for(int i=0;i<v.size();i++){
            nums[i]=v[i];

        }
        return k;
    }
};