class Solution {
public:
    int singleNumber(vector<int>& nums) {
        if(nums.size()==1) return nums[0];
        unordered_map<int,int>mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
            if(mp[nums[i]]==2) mp.erase(nums[i]);

        }
        for(auto ele : mp){
             return ele.first;
        }
        return 0;
    }
};