#define ll long long
int mod=1e9+7;
int dp[105][105];
ll int dfs(int n,int goal,int k)
{
    if(n==0 && goal==0)
    {
        return 1;
    }
    if(n==0 || goal==0)
    {
        return 0;
    }
    
    if(dp[n][goal]!=-1)
    {
        return dp[n][goal];
    }
    
    ll int pick=dfs(n-1,goal-1,k)*n;
    ll int not_pick=dfs(n,goal-1,k)*max(0,n-k);
    
    return dp[n][goal]=(pick+not_pick)%mod;
}
class Solution 
{
public:
    int numMusicPlaylists(int n, int goal, int k) 
    {
        memset(dp,-1,sizeof(dp));
        return dfs(n,goal,k);
    }
};
