//Method-1: 

int ct(int index,vector<int>&cost,vector<int>&dp)
{
    if(index==-1)
    {
        return min(ct(0,cost,dp),ct(1,cost,dp));
    }
    int n=cost.size();
    if(index>=n)
        return 0;
    if(dp[index]!=-1)
        return dp[index];
    int a=ct(index+2,cost,dp)+cost[index];
    int b=ct(index+1,cost,dp)+cost[index];
    return dp[index]=min(a,b);
}
class Solution 
{
public:
    int minCostClimbingStairs(vector<int>& cost) 
    {
        int n=cost.size();
        vector<int>dp(n+1,-1);
        return ct(-1,cost,dp);
    }
};

//Method-2 : 

class Solution 
{
public:
    int minCostClimbingStairs(vector<int>& cost) 
    {
        int n=cost.size();
        int dp[n+1];
        dp[0]=0;
        dp[1]=0;
        for(int i=2;i<=n;i++)
        {
            dp[i]=min(cost[i-1]+dp[i-1],cost[i-2]+dp[i-2]);
        }
        return dp[n];
    }
};
