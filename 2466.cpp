//Method-1 : 


int mod=1e9+7;
int ways(int &low,int &high,int len,int &one,int &zero,vector<int>&dp)
{
    if(len>high)
    {
        return 0;
    }
    if(dp[len]!=-1)
    {
        return dp[len];
    }
    int a=ways(low,high,len+zero,one,zero,dp);
    int b=ways(low,high,len+one,one,zero,dp);
    if(len>=low && len<=high)
    {
        return dp[len]=(1+a+b)%mod;
    }
    return dp[len]=(a+b)%mod;
}
class Solution 
{
public:
    int countGoodStrings(int low, int high, int zero, int one) 
    {
        vector<int>dp(high+1,-1);
        return ways(low,high,0,one,zero,dp); 
    }
};
