int dp[505][505];
int dfs(int l,int r,vector<int>&a,int x)
{
    if(l>=r)
    {
        return 0;
    }
    if(dp[l][r]!=-1)
    {
        return dp[l][r];
    }
    int ans=min({min(x,a[l+1]-a[l])+dfs(l+2,r,a,x),min(x,a[r]-a[l])+dfs(l+1,r-1,a,x),min(x,a[r]-a[r-1])+dfs(l,r-2,a,x)});
    return dp[l][r]=ans;
}
class Solution 
{
public:
    int minOperations(string s1, string s2, int x) 
    {
        vector<int>vec;
        int n=s1.size();
        for(int i=0;i<n;i++)
        {
            if(s1[i]!=s2[i])
            {
                vec.push_back(i);
            }
        }
        int sz=vec.size();
        memset(dp,-1,sizeof(dp));
        if(vec.size()%2!=0)
        {
            return -1;
        }
        return dfs(0,sz-1,vec,x);
    }
};
