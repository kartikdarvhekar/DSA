class Solution {
public:
    
    bool checkDivisibility(int n) {
        int x=n;
        vector<int>v;
        while(x!=0){
            int k=x%10;
            v.push_back(k);
            x=x/10;

        }
        int sum=0;
        int prod=1;
        for(int i=0;i<v.size();i++){
            sum=sum+v[i];
            prod*=v[i];
        }
        int ans=sum+prod;
        if(n%ans==0) return true ;
        else return false;
    }
};