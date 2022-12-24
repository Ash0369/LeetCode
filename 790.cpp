//https://leetcode.com/problems/domino-and-tromino-tiling/discuss/2132473/C%2B%2B-DP-faster-than-100.00-Explained-with-image
//https://www.youtube.com/watch?v=TM3vA2s91u8

#define ll long long
int mod=1e9+7;
int ways(int index,int n,vector<ll int>&dp)
{
    if(index<0)
        return 0;
    if(index==0 || index==1)
        return 1;
    else if(index==2)
        return 2;
    if(dp[index]!=-1)
        return dp[index];
    return dp[index]=((1LL*2*ways(index-1,n,dp))+1LL*ways(index-3,n,dp))%mod;
}
class Solution 
{
public:
    int numTilings(int n) 
    {
        vector<ll int>dp(n+1,-1);
        return ways(n,n,dp);
    }
};
