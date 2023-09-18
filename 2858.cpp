void dfs(int index,int parent,vector<vector<int>>&tree, vector<vector<int>>&rtree,vector<int>&dp)
{
    int sz1=tree[index].size();
    int sz2=rtree[index].size();
    for(auto x:tree[index])
    {
        if(x!=parent)
        {
            dfs(x,index,tree,rtree,dp);
            dp[index]+=dp[x];
        }
    }
    for(auto x:rtree[index])
    {
        if(x!=parent)
        {
            dfs(x,index,tree,rtree,dp);
            dp[index]+=1+dp[x];
        }
    }
}

void dfs2(int index,int parent,bool con,vector<vector<int>>&tree, vector<vector<int>>&rtree,vector<int>&ans,int prev)
{
    int need=prev;
    if(con)
    {
        ans[index]=need+1;
    }
    else
    {
        ans[index]=need-1;
    }
    if(parent==-1)
    {
        ans[index]=prev;
    }
    for(auto x:tree[index])
    {
        if(x!=parent)
        {
            dfs2(x,index,true,tree,rtree,ans,ans[index]);
        }
    }
    for(auto x:rtree[index])
    {
        if(x!=parent)
        {
            dfs2(x,index,false,tree,rtree,ans,ans[index]);
        }
    }
}

class Solution 
{
public:
    vector<int> minEdgeReversals(int n, vector<vector<int>>& edges) 
    {
        vector<vector<int>>tree(n+2);
        vector<vector<int>>rtree(n+2);
        for(auto x:edges)
        {
            int u=x[0];
            int v=x[1];
            tree[u].push_back(v);
            rtree[v].push_back(u);
        }
        vector<int>dp(n+2,0);
        dfs(0,-1,tree,rtree,dp);
        vector<int>ans(n,0);
        dfs2(0,-1,true,tree,rtree,ans,dp[0]);
        return ans;
    }
};
