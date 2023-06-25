int dp[105][205];
int mod=1000000007;
int dfs(int index,vector<int>& locations,int finish,int fuel)
{
    int ans=0;
    if(dp[index][fuel]!=-1)
    {
        return dp[index][fuel];
    }
    for(int i=0;i<locations.size();i++)
    {
        if(index==i || abs(locations[index]-locations[i])>fuel)
        {
            continue;
        }
        ans=(ans+dfs(i,locations,finish,fuel-abs(locations[index]-locations[i])))%mod;
    }
    if(index==finish)
    {
        return dp[index][fuel]=(1+ans)%mod;
    }
    return dp[index][fuel]=ans;
}
class Solution 
{
public:
    int countRoutes(vector<int>& locations, int start, int finish, int fuel) 
    {
        memset(dp,-1,sizeof(dp));
        return dfs(start,locations,finish,fuel);
    }
};
