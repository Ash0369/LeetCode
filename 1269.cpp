//Method-1:


#define mod 1000000007
#define ll long long

ll int dp[501][501];
ll int ways(int curr,int step,int arr)
{
    if(curr>505)
    {
        return 0;
    }
    if(step==0)
    {
        return curr==0;
    }
    if(dp[curr][step]!=-1)
    {
        return dp[curr][step];
    }
    ll int w=0;
    if(curr+1<arr)
    {
        w=(w+ways(curr+1,step-1,arr))%mod;
    }
    if(curr-1>=0)
    {
        w=(w+ways(curr-1,step-1,arr))%mod;
    }
    w=(w+ways(curr,step-1,arr))%mod;
    return dp[curr][step]=w;
}
class Solution 
{
public:
    int numWays(int steps, int arrLen) 
    {
        memset(dp,-1,sizeof(dp));
        return ways(0,steps,arrLen);
    }
};


//Method-2:

#define mod 1000000007
#define ll long long
ll int dp[505][505];
class Solution 
{
public:
    int numWays(int steps, int arrLen) 
    {
        int n=min(arrLen,500);
        memset(dp,0,sizeof(dp));
        dp[0][steps]=1;
        for(int i=steps-1;i>=0;i--)
        {
            for(int j=0;j<n;j++)
            {
                ll int extra=dp[j][i+1];
                if(j-1>=0)
                {
                    extra=(extra+dp[j-1][i+1])%mod;
                }
                if(j+1<n)
                {
                    extra=(extra+dp[j+1][i+1])%mod;
                }
                dp[j][i]=(dp[j][i]+extra)%mod;
            }
        }
        return dp[0][0];
    }
};
