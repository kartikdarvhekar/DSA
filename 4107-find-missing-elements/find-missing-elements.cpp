class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int n =nums.size();
        vector<int>ans;
        if(n==1) return ans;
        sort(nums.begin(),nums.end());
        int mn=nums[0];
        int mx=nums[n-1];
        int j=0;
        for(int i=mn;i<=mx;i++){
            if(nums[j]!=i) {
                ans.push_back(i);
                continue;
            }
            j++;
        }
        return ans;
    }
};