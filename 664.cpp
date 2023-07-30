int dfs(string &s,int l,int r,vector<vector<int>>&dp)
{
    
    if(l>r)
    {
        return 0;
    }
    if(dp[l][r]!=-1)
    {
        return dp[l][r];
    }
    int ans=1+dfs(s,l+1,r,dp);
    for(int k=l+1;k<=r;k++)
    {
        if(s[k]==s[l])
        {
            ans=min(ans,dfs(s,l+1,k-1,dp)+dfs(s,k,r,dp));
        }
    }
    return dp[l][r]=ans;
}
class Solution 
{
public:
    int strangePrinter(string s) 
    {
        int n=s.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return dfs(s,0,s.size()-1,dp);
    }
};
