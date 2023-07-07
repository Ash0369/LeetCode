int mod=1e9+7;
#define ll long long
int dp[1001][1001];
int dfs(int index,int sum,int k,vector<int>&nums)
{
    if(index==nums.size())
    {
        return sum<k;
    }
    if(dp[index][sum]!=-1)
    {
        return dp[index][sum];
    }
    int ans1=dfs(index+1,min(k,nums[index]+sum),k,nums);
    int ans2=dfs(index+1,sum,k,nums);
    return dp[index][sum]=(ans1+ans2)%mod;
}
ll int pwr(ll int a,ll int b)
{
    if(b==0)
        return 1;
    if(b%2==0){ll int ans1=pwr(a,b/2);ll int ans2=(ans1*ans1)%mod;return ans2;}
    ll int ans1=pwr(a,b/2);ll int ans2=(ans1*ans1)%mod;
    ans2=(ans2*a)%mod;
    return ans2;
}
class Solution 
{
public:
    int countPartitions(vector<int>& nums, int k) 
    {
        ll int tot=0;
        for(auto x:nums)
        {
            tot+=x;
        }
        if(tot<(2*k))
        {
            return 0;
        }
        int n=nums.size();
        memset(dp,-1,sizeof(dp[n+1])*1001);
        ll int ans=2*dfs(0,0,k,nums);
        //cout<<ans<<endl;
        tot=pwr(2,n);
        return ((tot%mod)-(ans%mod)+mod)%mod;
    }
};
