class Solution 
{
public:
    int minOperations(int n) 
    {
        int x=log2(n);
        if(pow(2,x)==n)
        {
            return 1;
        }
        int upper=pow(2,x+1);
        int lower=pow(2,x);
        int u=minOperations(upper-n);
        int l=minOperations(n-lower);
        return min(u+1,l+1);
    }
};
