class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        vector<int>arr1,arr2;
        int n=nums.size();
        if(n==0) return nums;
        if(n==1 || n==2) return nums;
        for(int i=0;i<n;i++){
            if(i==0) arr1.push_back(nums[0]);
            if(i==1) arr2.push_back(nums[i]);
            if(i>1){
                if(arr1[arr1.size()-1]>arr2[arr2.size()-1]) arr1.push_back(nums[i]);
                else arr2.push_back(nums[i]);
            }
        }
        vector<int>ans;
        for(int i=0;i<arr1.size();i++){
            ans.push_back(arr1[i]);
        }
        for(int j=0;j<arr2.size();j++){
            ans.push_back(arr2[j]);
        }
        return ans;
    }
};