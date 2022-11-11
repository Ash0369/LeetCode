bool dfs(int node,int intial,vector<int>adj[],vector<int>&color)
{
    if(color[node]!=-1)
    {
        if(color[node]==intial)
        {
            return false;
        }
        else
        {
            return true;
        }
    }
    color[node]=!intial;
    for(auto x:adj[node])
    {
        if(dfs(x,color[node],adj,color)==false)
        {
            return false;
        }
    }
    return true;
    
}
class Solution 
{
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) 
    {
        vector<int>dp(n+1,-1);
        vector<int>graph[n+1];
        for(auto x:dislikes)
        {
            int a=x[0];
            int b=x[1];
            graph[a].push_back(b);
            graph[b].push_back(a);
        }
        for(int i=1;i<=n;i++)
        {
            if(dp[i]==-1)
            {
                if(dfs(i,0,graph,dp)==false)
	            {
	                return false;
	            }
            }
        }
        return true;
    }
};
