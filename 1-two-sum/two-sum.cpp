class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int>ans;
        unordered_map<int,int>m;
        // val and index
        for(int i=0;i<nums.size();i++){
            int rem=target-nums[i];
            if(m.find(rem)!=m.end()){
                ans.push_back(i);
                ans.push_back(m[rem]);
            }
            else m[nums[i]]=i;
        }
        return ans;
    }
};