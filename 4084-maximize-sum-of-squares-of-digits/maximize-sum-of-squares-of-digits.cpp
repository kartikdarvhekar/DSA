class Solution {
public:
    string maxSumOfSquares(int num, int sum) 
    {
        string result="";
        if(num*9<sum)  //Corner Case
            return result;
        int nines=sum/9;
        for(int i=0;i<nines;i++)
            result.append("9");
        int rem=sum%9;
        if(result.size()==num)
            return result;
        else
        {
            while(result.size()!=num)
            {
                result.append(to_string(rem));
                rem=rem/9;
            }
        }

        return result;
    }
};
