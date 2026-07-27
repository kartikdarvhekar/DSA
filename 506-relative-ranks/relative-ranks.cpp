class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        priority_queue<pair<int,int>>pq;
        int n=score.size();
        for(int i=0;i<n;i++){
            pq.push({score[i],i});
        }
        vector<string>ans(n);
        int j=1;
        while(true){
            if(j>n) break;
            int x=pq.top().first;
            int idx=pq.top().second;
            if(j==1) ans[idx]="Gold Medal";
            if(j==2) ans[idx]="Silver Medal";
            if(j==3) ans[idx]="Bronze Medal";
            if(j>3)break;
            pq.pop();
            j++;
        }
        if(pq.size()>0){
        for(int i=4;i<=n;i++){
            int idx=pq.top().second;
            ans[idx]= to_string(i);
            pq.pop();
        }
        }
        return ans;
    }
};