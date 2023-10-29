#define ll long long
ll int dp[100005][17];
vector<int>d={1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768,65536,131072};
ll int dfs(vector<vector<int>>&tree,int index,int parent,vector<int>& coins,int k,int f)
{
    if(dp[index][f]!=10000000000)
    {
        return dp[index][f];
    }
    ll int ans1=0;
    ll int ans2=0;
    for(auto x:tree[index])
    {
        if(x==parent)
        {
            continue;
        }
        ans1+=dfs(tree,x,index,coins,k,f);
        ans2+=dfs(tree,x,index,coins,k,min(15,f+1));
    }
    int av=coins[index]/d[f];
    int take1=(av/2)+ans2;
    int take2=av-k;
    take2+=ans1;
    return dp[index][f]=max(take1,take2);
}
class Solution 
{
public:
    int maximumPoints(vector<vector<int>>& edges, vector<int>& coins, int k) 
    {
        int n=coins.size();
        vector<vector<int>>tree(n+1);
        for(auto x:edges)
        {
            tree[x[0]].push_back(x[1]);
            tree[x[1]].push_back(x[0]);
        }
        for(int i=0;i<=n+2;i++)
        {
            for(int j=0;j<=15;j++)
            {
                dp[i][j]=10000000000;
            }
        }
        return dfs(tree,0,-1,coins,k,0);
    }
};
