class Solution {
public:
    int lastStoneWeight(vector<int>& nums) {
        priority_queue<int>pq;
        int n=nums.size();
        for(int i=0;i<n;i++){
            pq.push(nums[i]);
        }
        while(pq.size()>1){
            int x=pq.top();
            pq.pop();
            int y=pq.top();
            pq.pop();
            int dis=x-y;
            if(x!=y) pq.push(dis); 
        }
        if(pq.size()==1) return pq.top();
        return 0;
    }
};