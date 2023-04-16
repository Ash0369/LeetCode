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
