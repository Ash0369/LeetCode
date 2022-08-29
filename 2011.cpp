class Solution 
{
public:
    int finalValueAfterOperations(vector<string>& operations) 
    {
        int a=0;
        for(auto x:operations)
        {
            if(x[0]=='+' || x[2]=='+')
            { 
                a++;
            }
            if(x[0]=='-' || x[2]=='-')
            {
                a--;
            }
        }
        return a;
    }
};
