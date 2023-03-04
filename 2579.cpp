class Solution 
{
public:
    long long coloredCells(int n) 
    {
        if(n==1)
        {
            return 1;
        }
        long long int ans=1;
        for(int i=0;i<n-1;i++)
        {
            ans=ans+(4+(1LL*4*i));
        }
        return ans;
    }
};
