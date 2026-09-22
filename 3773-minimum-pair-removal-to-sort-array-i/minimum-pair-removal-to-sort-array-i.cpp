class Solution {
public:
    
    int minimumPairRemoval(vector<int>& nums) {
         vector<int>v=nums;
         sort(v.begin(),v.end());
         if(v==nums) return 0;
         priority_queue< pair<int,pair<int,int>> , vector<pair<int,pair<int,int>>> , greater<pair<int,pair<int,int>>> >pq;
         // pq= {sum,{indx1,indx2}}
         for(int i=0;i<nums.size()-1;i++){
            pq.push({nums[i]+nums[i+1],{i,i+1}});
         }

         int count=0;
         while(true){
            
            int sum=pq.top().first;
            int minIdx=pq.top().second.first;
            int maxIdx=pq.top().second.second;
            nums[minIdx]=sum;
            nums.erase(nums.begin()+maxIdx);
           
            count++;
            vector<int>comp=nums;
            sort(comp.begin(),comp.end());
            if(comp==nums) return count;
            pq.pop();

            pq=decltype(pq)();
            for(int i=0;i<nums.size()-1;i++){
            pq.push({nums[i]+nums[i+1],{i,i+1}});
         }

         }
         return count;

        
    }
};