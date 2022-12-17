int find(int n,vector<int>&dp)
{
    if(n==0)
        return 1;
    int curr=0;
    if(dp[n]!=-1)
        return dp[n];
    for(int i=1;i<=(n/2);i++)
    {
        int first=i;
        int second=n-i;
        int a=max(first,find(first,dp));//We are taking max because might be after beaking it can be less then a.
        int b=max(second,find(second,dp));
        curr=max(curr,a*b);
    }
    return dp[n]=curr;
}
class Solution 
{
public:
    int integerBreak(int n) 
    {
        vector<int>dp(n+1,-1);
        int ans=find(n,dp);
        return ans;
    }
};
