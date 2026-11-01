class Solution {
public:
    int minMoves(vector<int>& nums) {
        if(nums.size()==1) return 0;
        int count=0;
      
        vector<int>v=nums;
        sort(v.begin(),v.end());
        int mn=v[0];
        for(int i=0;i<nums.size();i++){
            if(nums[i]>mn) count+=nums[i]-mn;
            
        }
        return count;

    }
};