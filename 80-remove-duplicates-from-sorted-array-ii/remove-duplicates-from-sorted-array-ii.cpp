class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int ans=0;
        vector<int>arr;
        unordered_map<int,int>mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        for(auto ele : mp){
            if(ele.second==1){
                 ans++;
                 arr.push_back(ele.first);
            }
            if(ele.second==2){
                 ans=ans+2;
                 arr.push_back(ele.first);
                 arr.push_back(ele.first);
                 
            }
            if(ele.second>2){
                
                 ans=ans+2;
                  arr.push_back(ele.first);
                 arr.push_back(ele.first);

            }

        }
         sort(arr.begin(),arr.end());
        for(int i=0;i<arr.size();i++){
            nums[i]=arr[i];
        }
       
        return ans;
    }
};