//Method-1 : 

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


//Method-2 : 

class Solution 
{
public:
    int numRollsToTarget(int n, int k, int target) 
    {
        vector<vector<int>>dp(n+1,vector<int>(target+1,0));
        
        for(int i=1;i<=k && i<=target;i++)
        {
            dp[1][i]=1;
        }
        
        for(int i=2;i<=n;i++)
        {
            for(int j=0;j<=target;j++)
            {
                int res=0;
                for(int a=1;a<=k & j-a>=0;a++)
                {
                    res=(res+dp[i-1][j-a])%mod;
                }
                dp[i][j]=res;
            }
        }
        
        return dp[n][target];
    }
};

