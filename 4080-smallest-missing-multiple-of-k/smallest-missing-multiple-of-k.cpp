class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_set<int>s;
        for(int i=0;i<nums.size();i++){
            if(nums[i]%k==0) s.insert(nums[i]);
        }
        for(int i=1;i<s.size()+2;i++){
            if(s.find(k*i)==s.end()) return k*i;
        }
        return k;
    }
};