class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        if(nums.size()==1) return 0;
        int n=nums.size();
        int mid=nums[n/2];
        int ans=0;
        for(int i=0;i<n;i++){
             if(mid-nums[i]>0){
                ans+=mid-nums[i];
             }
             if(mid-nums[i]<0){
                ans+=nums[i]-mid;
             }
             
        }
        return ans;
    }
};