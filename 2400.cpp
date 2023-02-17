int mod=1e9+7;
int way(int curr,int end,int k,vector<vector<int>>&dp)
{
    if(curr==end && k==0)
    {
        return 1;
    }
    if(k==0)
    {
        return 0;
    }
    if(dp[curr][k]!=-1)
    {
        return dp[curr][k];
    }
    int a=way(curr+1,end,k-1,dp);
    int b=way(curr-1,end,k-1,dp);
    
    return dp[curr][k]=(a+b)%mod;
}
class Solution 
{
public:
    int numberOfWays(int startPos, int endPos, int k) 
    {
        startPos+=1000;
        endPos+=1000;
        vector<vector<int>>dp(3005,vector<int>(1005,-1));
        return way(startPos,endPos,k,dp);
    }
};
