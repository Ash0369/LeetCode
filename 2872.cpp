#define ll long long

int ans=0;
ll int dfs(int index,int parent,vector<vector<int>>&tree,vector<int>&values,int k)
{
    ll int tot=0;
    for(auto x:tree[index])
    {
        if(x==parent)
        {
            continue;
        }
        tot+=dfs(x,index,tree,values,k);
    }
    tot+=values[index];
    if(tot%k==0)
    {
        ans++;
        tot=0;
    }
    return tot;
}
class Solution 
{
public:
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) 
    {
        vector<vector<int>>tree(n+1);
        for(auto x:edges)
        {
            tree[x[0]].push_back(x[1]);
            tree[x[1]].push_back(x[0]);
        }
        ans=0;
        dfs(0,-1,tree,values,k);
        return ans;
    }
};
