class Solution {
public:
    int rev(int n){
        int t=0;
        while(n>0){
            t=t*10;
            t=t+(n%10);
            n=n/10;

        }
       return t;
    }
    int countNicePairs(vector<int>& arr) {
        int n=arr.size();
        for(int i=0;i<n;i++){
            arr[i]=arr[i]-rev(arr[i]);
        }
        unordered_map<int,int>m;
        //   arr[i],freq
       
        int count=0;
        for(int i=0;i<n;i++){
            if(m.find(arr[i])!=m.end()){
                count=count%1000000007;
                count+=m[arr[i]];
                m[arr[i]]++;
            }
            else m[arr[i]]++;
        }
        return count%1000000007;
    }
};