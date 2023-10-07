int mod=1000000007;
#define ll long long
ll int dp[52][52][102];
ll int dfs(int n,int m,int k,int prev)
{
    if(n==0)
    {
        return k==0;
    }
    if(dp[n][k][prev]!=-1)
    {
        return dp[n][k][prev];
    }
    ll int ans=0;
    for(int i=1;i<=m;i++)
    {
        if(prev==(m+1) || i>prev)
        {
            if(k==0)
            {
                continue;
            }
            ans=(ans+dfs(n-1,m,k-1,i))%mod;
        }
        else
        {
            ans=(ans+dfs(n-1,m,k,prev))%mod;
        }
    }
    return dp[n][k][prev]=ans;
}
class Solution 
{
public:
    int numOfArrays(int n, int m, int k) 
    {
        memset(dp,-1,sizeof(dp));
        return dfs(n,m,k,m+1);
    }
};
