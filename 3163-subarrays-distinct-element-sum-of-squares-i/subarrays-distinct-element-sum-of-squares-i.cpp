class Solution {
public:
    int sumCounts(vector<int>& nums) {
        if(nums.size()==1) return 1;
        int sum=nums.size();
        for(int k=1;k<nums.size();k++){
            int i=0;
            int j=k;
            while(j<nums.size()){
                unordered_set<int>st;
                for(int p=i;p<=j;p++){
                    st.insert(nums[p]);
                }
                sum+=st.size()*st.size();
                i=i+1;
                j=j+1;

            }
        }
        return sum;
    }
};