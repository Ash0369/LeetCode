int mod=1e9+7;
int ways(int index,int target,vector<vector<int>>&types,vector<vector<int>>&dp)
{
    int n=types.size();
    if(target==0)
    {
        return 1;
    }
    if(index==n || target<0)
    {
        return 0;
    }
    if(dp[index][target]!=-1)
    {
        return dp[index][target];
    }
    int ans=0;
    for(int i=0;i<=types[index][0];i++)
    {
        ans=(ans+ways(index+1,target-(i*types[index][1]),types,dp))%mod;
    }
    return dp[index][target]=ans;
}
class Solution 
{
public:
    int waysToReachTarget(int target, vector<vector<int>>& types) 
    {
        vector<vector<int>>dp(types.size()+1,vector<int>(target+1,-1));
        return ways(0,target,types,dp);
    }
};
