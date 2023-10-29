#define ll long long
ll int dp[100005][2][2];
ll int dfs(int index,vector<int>& nums,int k,int prev,int lprev)
{
    int n=nums.size();
    if(index==n)
    {
        return 0;
    }
    if(dp[index][prev][lprev]!=-1)
    {
        return dp[index][prev][lprev];
    }
    if(nums[index]>=k)
    {
        return dp[index][prev][lprev]=dfs(index+1,nums,k,1,1);
    }
    int need=max(0,k-nums[index]);
    ll int val2=need+dfs(index+1,nums,k,1,1);
    if(lprev==0)
    {
        return dp[index][prev][lprev]=val2;
    }
    
    ll int val1=dfs(index+1,nums,k,0,prev);
    return dp[index][prev][lprev]=min(val1,val2);
}
class Solution 
{
public:
    long long minIncrementOperations(vector<int>& nums, int k) 
    {
        int n=nums.size();
        for(int i=0;i<=n+2;i++)
        {
            for(int j=0;j<=1;j++)
            {
                for(int p=0;p<=1;p++)
                {
                    dp[i][j][p]=-1;
                }
            }
        }
        return dfs(0,nums,k,1,1);
    }
};
