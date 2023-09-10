int mod=1e9+7;
class Solution 
{
public:
    int countOrders(int n) 
    {
        vector<long long int>dp(n+10,0);
        dp[0]=1;
        for(int i=1;i<=n;i++)
        {
            int av=(2*i)+1;
            av=av*(i+1)%mod;
            if(i==1)
            {
                av=1;
            }
            dp[i]=(dp[i-1]*av)%mod;
        }
        return dp[n];
    }
};
