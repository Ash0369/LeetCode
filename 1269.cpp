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
