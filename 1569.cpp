int mod=1e9+7;
#define ll long long
vector<vector<ll int>>dp;
ll mod_sub(ll a, ll b) {a = a % mod; b = b % mod; return (((a - b) % mod) + mod) % mod;}
ll int dfs(vector<int>&nums)
{
    int n=nums.size();
    if(n<=2)
    {
        return 1;
    }
    vector<int>left;
    vector<int>right;
    for(int i=1;i<n;i++)
    {
        if(nums[i]<nums[0])
        {
            left.push_back(nums[i]);
        }
        else
        {
            right.push_back(nums[i]);
        }
    }
    ll int lans=dfs(left);
    ll int rans=dfs(right);
    
    ll int ans=(dp[n-1][int(left.size())]*lans)%mod;
    ans=(ans*rans)%mod;
    return ans;
}
class Solution 
{
public:
    int numOfWays(vector<int>& nums) 
    {
        int n=nums.size();
        dp.resize(n+5);
        for(int i=0;i<=n;i++)
        {
            dp[i]=vector<ll int>(i+1,1);
            for(int j=1;j<i;j++)
            {
                dp[i][j]=(dp[i-1][j-1]+dp[i-1][j])%mod;
            }
        }
        return mod_sub(dfs(nums),1);
    }
};
