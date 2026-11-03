class Solution {
public:
    int minMoves(vector<int>& nums) {
        if(nums.size()==1) return 0;
        vector<int>arr=nums;
        sort(arr.begin(),arr.end());
        int mx=arr[nums.size()-1];
        int count=0;
        for(int i=0;i<nums.size();i++){
            count+=mx-nums[i];
        }
        return count;
    }
};