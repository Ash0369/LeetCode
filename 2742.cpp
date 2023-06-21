#define ll long long
int n;
ll int dp[505][505];
ll int dfs(int index,vector<int>&cost,vector<int>&time,int ava)
{
    if(ava<=0)
    {
        return 0;
    }
    if(index==n)
    {
        return 1e9;
    }
    if(dp[index][ava]!=-1)
    {
        return dp[index][ava];
    }
    ll int ans1=cost[index]+dfs(index+1,cost,time,ava-1-time[index]);
    ll int ans2=dfs(index+1,cost,time,ava);
    return dp[index][ava]=min(ans1,ans2);
}
class Solution 
{
public:
    int paintWalls(vector<int>& cost, vector<int>& time) 
    {
        n=cost.size();
        memset(dp,-1,sizeof(dp));
        return dfs(0,cost,time,n);
    }
};
