int mod=1e9+7;
int c[10005][20];
#define ll long long
class Solution 
{
public:
    int idealArrays(int n, int m) 
    {
        int dp[m+1][20];
        memset(dp,0,sizeof(dp));
        for(int i=1;i<=m;i++)
        {
            dp[i][1]=1;
        }
        for(int j=1;j<14;j++)
        {
            for(int i=1;i<=m;i++)
            {
                for(int k=2;i*k<=m;k++)
                {
                    dp[k*i][j+1]=(dp[i][j]+dp[k*i][j+1])%mod;
                }
            }
        }
        memset(c,0,sizeof(c));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<=14 && j<=i;j++)
            {
                if(j==0)
                {
                    c[i][j]=1;
                }
                else
                {
                    c[i][j]=(c[i-1][j-1]+c[i-1][j])%mod;
                    
                }
            }
        }
        
        ll int ans=0;
        
        for(int i=1;i<=m;i++)
        {
            for(int j=1;j<=14 && j<=n;j++)
            {
                ans=(ans+(1LL*dp[i][j]*c[n-1][j-1]))%mod;
            }
        }
        return ans;
        
    }
};
