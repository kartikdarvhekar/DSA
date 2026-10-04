class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int>ans;
        unordered_map<int,int>mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        priority_queue< pair<int,int>,vector< pair<int,int>>,greater< pair<int,int>>>pq;
        priority_queue< pair<int,int>,vector< pair<int,int>>,greater< pair<int,int>>>k;
        for(auto ele:mp){
            pq.push({ele.first,ele.second});
        }
        while(ans.size()!=nums.size()){

        while(pq.size()!=0){
            ans.push_back(pq.top().first);
            if(pq.top().second==1){
                pq.pop();
            }
            else{
               
                k.push({pq.top().first,pq.top().second-1});
                pq.pop();
            }
            
        }
           swap(pq,k);
        }
        return ans;

       
    }
};