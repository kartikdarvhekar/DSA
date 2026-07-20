class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        priority_queue< pair<int,int> ,vector<pair<int,int>>,greater<pair<int,int>> >pq;
        int n=nums.size();
        // freq,number;
        unordered_map<int,int>m;
        for(auto ele : nums){
            m[ele]++;

        }
        for(auto ele : m){
            int number=-ele.first;
            int freq=ele.second;
            pq.push({freq,number});
        }
        vector<int>ans;
        while(pq.size()>0){
            int fre=pq.top().first;
            int val=-pq.top().second;
            for(int i=0;i<fre;i++){
                ans.push_back(val);
            }
            pq.pop();
        }

        return ans;
    }
};