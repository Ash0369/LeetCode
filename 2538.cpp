#define ll long long
ll int dp[100005];
void dfs(int index,int parent,vector<vector<int>>&tree,vector<int>&price)
{
    dp[index]=0;
    for(auto x:tree[index])
    {
        if(x==parent)
        {
            continue;
        }
        dfs(x,index,tree,price);
        dp[index]=max(dp[index],dp[x]);
    }
    dp[index]+=price[index];
}
ll int ans;
void dfs2(int index,int parent,ll int prev,vector<vector<int>>&tree,vector<int>&price)
{
    ll int child=0;
    ll int max1=0;
    ll int max2=0;
    int node1=0;
    int node2=0;
    for(auto x:tree[index])
    {
        if(x==parent)
        {
            continue;
        }
        child=max(child,dp[x]);
        if(dp[x]>=max1)
        {
            node2=node1;
            max2=max1;
            max1=dp[x];
            node1=x;
        }
        else if(dp[x]>max2)
        {
            max2=dp[x];
            node2=x;
        }
    }
    child=max(child,prev);
    ans=max(ans,child+price[index]-price[index]);
    
    if(prev>max1)
    {
        node2=node1;
        max2=max1;
        max1=prev;
        node1=-1;
    }
    else if(prev>max2)
    {
        node2=-1;
        max2=prev;
    }
    for(auto x:tree[index])
    {
        if(x==parent)
        {
            continue;
        }
        if(x!=node1)
        {
            dfs2(x,index,max1+price[index],tree,price);
        }
        else
        {
            dfs2(x,index,max2+price[index],tree,price);
        }
    }
}
class Solution 
{
public:
    long long maxOutput(int n, vector<vector<int>>& edges, vector<int>& price) 
    {
        ans=0;
        vector<vector<int>>tree(n+1);
        for(auto x:edges)
        {
            tree[x[0]].push_back(x[1]);
            tree[x[1]].push_back(x[0]);
        }
        dfs(0,-1,tree,price);
        dfs2(0,-1,0,tree,price);
        return ans;
    }
};
