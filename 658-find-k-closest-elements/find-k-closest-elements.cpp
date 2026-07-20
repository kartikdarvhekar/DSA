class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n=arr.size();
        priority_queue<pair<int,int>>pq; // distance and element
        for(int i=0;i<n;i++){
            int dis=abs(x-arr[i]);
            pq.push({dis,arr[i]});
            if(pq.size()>k) pq.pop();
        }
        vector<int>ans;
        while(pq.size()>0){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};