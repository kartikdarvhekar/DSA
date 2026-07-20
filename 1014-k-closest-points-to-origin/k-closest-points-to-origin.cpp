class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& arr, int k) {
        vector<vector<int>>ans;
       
        priority_queue< pair<int,vector<int>> >pq;
        for(auto v:arr){
            int x=v[0];
            int y=v[1];
            int dis=x*x + y*y;
            pq.push({dis,v});
            if(pq.size()>k) pq.pop();
        }
        while(pq.size()>0){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};