//Method-1 : 

#define ll long long
const int mod=1e9+7;
int dp[1001][1001];
ll int ways(int last,int ptr,vector<vector<int>>&vec,string &target)
{
    if(ptr==target.size())
    {
        return 1;
    }
    if(dp[last][ptr]!=-1)
    {
        return dp[last][ptr];
    }
    ll int ans=0;
    if(last+(target.size()-ptr)>vec.size())
    {
        return 0;
    }
    for(int i=last;i<vec.size();i++)
    {
        if(vec[i][target[ptr]-'a']>0)
        {
            int cnt=vec[i][target[ptr]-'a'];
            ll int temp=ways(i+1,ptr+1,vec,target);
            temp=(temp*cnt)%mod;
            ans=(ans+temp)%mod;
        }
    }
    return dp[last][ptr]=ans;
}
class Solution 
{
public:
    int numWays(vector<string>& words, string &target) 
    {
        int n=words[0].size();
        vector<vector<int>>vec(n,vector<int>(26,0));
        for(int i=0;i<words.size();i++)
        {
            for(int j=0;j<n;j++)
            {
                vec[j][words[i][j]-'a']++;
            }
        }
        memset(dp,-1,sizeof(dp));
        return ways(0,0,vec,target);
    }
};


//Method-2 : 

#define ll long long
const int mod=1e9+7;
class Solution 
{
public:
    int numWays(vector<string>& words, string &target) 
    {
        int n=words[0].size();
        vector<vector<int>>vec(n,vector<int>(26,0));
        for(int i=0;i<words.size();i++)
        {
            for(int j=0;j<n;j++)
            {
                vec[j][words[i][j]-'a']++;
            }
        }
        ll int dp[1001][1001];//dp[i][j] taking first i char and forming first j char
        memset(dp,0,sizeof(dp));
        dp[0][0]=1;
        for(int i=1;i<=n;i++)
        {
            dp[i][0]=1;//Not perfoming anything
            for(int j=1;j<=target.size();j++)
            {
                ll int cnt=vec[i-1][target[j-1]-'a'];
                dp[i][j]=(dp[i-1][j])+ (cnt*(dp[i-1][j-1]))%mod;
                dp[i][j]=dp[i][j]%mod;
            }
        }
        return dp[n][target.size()];
    }
};
