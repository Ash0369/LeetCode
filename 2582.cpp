class Solution 
{
public:
    int passThePillow(int n, int time) 
    {
        int intital=0;
        int d=time/(n-1);
        int rem=time%(n-1);
        if(d%2==0)
        {
            return rem+1;
        } 
        return n-rem;
    }
};
