class Solution {
public:
    int add(int x,int sum){
        
        if(x==0) return sum;
       
        sum=sum+(x%10);
        x=x/10;
        return add(x,sum);
        
    }

    int smallestIndex(vector<int>& nums) {
        
        for(int i=0;i<nums.size();i++){
            if(i==add(nums[i],0)) return i;
        }
        return -1;
    }
};