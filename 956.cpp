int offset=5000;
int dp[21][10005];
int dfs(int index,vector<int>&rods,int diff)
{
    if(index==rods.size())
    {
        if(diff==0)
        {
            return 0;
        }
        return -1e7;
    }
    if(dp[index][diff+offset]!=-1)
    {
        return dp[index][diff+offset];
    }
    int v=rods[index];
    int ans=dfs(index+1,rods,diff);
    ans=max(ans,dfs(index+1,rods,diff-v));
    ans=max(ans,rods[index]+dfs(index+1,rods,diff+v));
    return dp[index][diff+offset]=ans;
}
class Solution
{
public:
    int tallestBillboard(vector<int>& rods) 
    {
        memset(dp,-1,sizeof(dp));
        return max(0,dfs(0,rods,0));
    }
};
