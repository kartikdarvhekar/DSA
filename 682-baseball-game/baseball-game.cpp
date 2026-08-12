class Solution {
public:
    int calPoints(vector<string>& operation) {
        stack<int>st;
        int n=operation.size();
    
        int sum=0;
        for(int i=0;i<n;i++){
            if(operation[i]=="+"){
                int x=st.top();
                st.pop();
                int y=st.top();
                st.push(x);     
                st.push(x+y);
            }
            else{
                if(operation[i]=="D"){
                    int k=st.top();
                    st.push(k*2);
                }
                else{
                    if(operation[i]=="C"){
                        st.pop();
                    }
                    else{
                        st.push(stoi(operation[i]));
                    }
                }
            }

        }
        while(st.size()>0){
            sum=sum+st.top();
            st.pop();
        }
        return sum;
        
    }
};