int mod=1e9+7;
int helper(int n,int k,int target,vector<vector<int>>&dp)
{
    if(target<=0)
        return 0;
    if(n==1 && target<=k)
        return 1;
    if(n==1 && target>k)
        return 0;
   if(dp[n][target]==-1)
   {
        int res=0;
        for(int i=1;i<=k;i++)
        {
            res=(res+(helper(n-1,k,target-i,dp)))%mod;
        }
        dp[n][target]=res;
   }
    return dp[n][target];
}
class Solution 
{
public:
    int numRollsToTarget(int n, int k, int target) 
    {
        vector<vector<int>>dp(n+1,vector<int>(target+1,-1));
        return helper(n,k,target,dp);
    }
};
