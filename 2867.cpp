#define ll long long
class sieve_
{
    public:
    vector<bool>dp;
    sieve_(int n)
    {
        dp.resize(n+5,0);
        dp[1]=1;
        for(int i=2;i<=n;i++)
        {
            if(dp[i]==0)
            {
                for(int j=2LL*i;j<=n;j=j+i)
                {
                    dp[j]=1;
                }
            }
        }
    }
    bool is_prime(int n)
    {
        if(dp[n]==0)
        {
            return true;
        }
        return false;
    }
};

ll int dfs(int index,int parent,vector<vector<int>>&tree,vector<vector<ll int>>&dp,vector<bool>&prime)
{
    ll int ans=0;
    for(auto x:tree[index])
    {
        if(x==parent)
        {
            continue;
        }
        ans+=dfs(x,index,tree,dp,prime);
        if(prime[index]==0)
        {
            ans+=dp[x][0];
            ans+=(dp[index][0])*dp[x][0];
        }
        else
        {
            ans+=dp[x][1];
            ans+=(dp[index][1])*dp[x][0];
            ans+=(dp[index][0])*dp[x][1];
            if(index==1 && x==2)
            {
                cout<<(dp[index][0]-dp[x][0])*dp[x][1]<<endl;
            }
        }
        dp[index][0]+=dp[x][0];
        dp[index][1]+=dp[x][1];
    }
    if(prime[index]==0)
    {
        dp[index][1]=1+dp[index][0];
        dp[index][0]=0;
    }
    else
    {
        dp[index][0]+=1;
    }
    return ans;
}
class Solution 
{
public:
    long long countPaths(int n,vector<vector<int>>& edges) 
    {
        sieve_ s(n+3);
        vector<vector<int>>tree(n+5);
        for(auto x:edges)
        {
            tree[x[0]].push_back(x[1]);
            tree[x[1]].push_back(x[0]);
        }
        vector<vector<ll int>>dp(n+2,vector<ll int>(3,0));
        return dfs(1,0,tree,dp,s.dp);
    }
};
