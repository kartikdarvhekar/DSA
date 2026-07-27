class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        int n=arr.size();
        for(int i=0;i<n;i++){
            pq.push({arr[i],i});
        }
        vector<int>ans(n);
        int i=1;
        while(pq.size()>0){
            int x=pq.top().first;
            int idx=pq.top().second;
            pq.pop();
            ans[idx]=i;
            if(pq.top().first==x) continue;
            i++;

        }
        return ans;
    }
};