#define ll long long
int mod=1e9+7;

ll int dfs(int ele,int n,int x,vector<vector<ll int>>&dp)
{
   
    if(ele==n+1 || pow(ele,x)>n)
    {
        return 0;
    }
    if(pow(ele,x)==n)
    {
        return 1;
    }
     if(dp[n][ele]!=-1)
    {
        return dp[n][ele];
    }
    
    return dp[n][ele]=(dfs(ele+1,n-pow(ele,x),x,dp)+dfs(ele+1,n,x,dp))%mod;
}
class Solution 
{
public:
    int numberOfWays(int n, int x) 
    {
        vector<vector<ll int>>dp(n+1,vector<ll int>(n+1,-1));
        return dfs(1,n,x,dp);
    }
};
