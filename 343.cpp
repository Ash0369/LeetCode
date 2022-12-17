//Method-1 : Recursive

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


//Method-2 : Iteratitive

class Solution 
{
public:
    int integerBreak(int n) 
    {
        vector<int>dp(n+1,0);
        for(int i=0;i<=n;i++)
            dp[i]=i;
        //dp[i] denotes maximum product if we break i in more then 2 parts.
        dp[1]=1;
        for(int i=2;i<=n;i++)
        {
            dp[i]=0;
            for(int j=1;j<i;j++)
            {
                int first=j;
                int second=i-j;
                dp[i]=max(dp[i],max(first,dp[first])*max(second,dp[second]));
            }
        }
        return dp[n];
    }
};
