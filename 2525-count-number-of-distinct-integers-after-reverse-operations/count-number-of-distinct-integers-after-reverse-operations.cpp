class Solution {
public:
    int reverse(int n){
        int r=0;
        while(n>0){
           r=r*10;
           r=r+(n%10);
           n=n/10;

        }
        return r;
    }
    int countDistinctIntegers(vector<int>& arr) {
       int n=arr.size();
       unordered_set<int>s;
       for(int i=0;i<n;i++){
           int rev=reverse(arr[i]);
           s.insert(arr[i]);
           s.insert(rev);
       }
       return s.size();
    }
};