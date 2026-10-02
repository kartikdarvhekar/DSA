class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int zero=0;
        queue<int>q;
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=0) q.push(nums[i]);
            else zero++;
        }
        int n=nums.size();
        for(int j=0;j<n;j++){
            if(q.size()==0) nums[j]=0;
            else{
                 nums[j]=q.front();
                 q.pop();
            }
        }
        return ;

    }
};