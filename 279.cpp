class Solution 
{
public:
    int numSquares(int n) 
    {
        int dp[n+1];
        dp[0]=0;
        dp[1]=1;
        //dp[i] dentes min no of perfect square that sum to n
        for(int i=2;i<=n;i++)
        {
            int a=sqrt(i);
            if(a*a==i)
            {
                dp[i]=1;
                continue;
            }
            int x=1;
            int temp=n;
            int d=i-1;
            while(d>0)
            {
                temp=min(temp,dp[d]);
                x++;
                d=i-int(pow(x,2));
            }
            dp[i]=1+temp;
            
        }
        return dp[n];
    }
};
