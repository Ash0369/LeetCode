int dfs(int node,vector<vector<pair<int,int>>>&graph,int available,vector<int>&passingFees, vector<vector<int>>&dp)
{
    int ans=INT_MAX;
    int n=passingFees.size();
    if(node==n-1)
    {
        return passingFees[node];
    }
    
    if(dp[node][available]!=-1)
        return dp[node][available];
    
    for(auto x:graph[node])
    {
        if(available>=x.second)
        {
            int cost=dfs(x.first,graph,available-x.second,passingFees,dp);
            if(cost!=INT_MAX)
            {
                ans=min(ans,cost+passingFees[node]);
            }
        }
    }
    if(ans==INT_MAX)
        return dp[node][available]=INT_MAX;
    
    return dp[node][available]=ans;
}
class Solution 
{
public:
    int minCost(int maxTime,vector<vector<int>>&edges,vector<int>&passingFees) 
    {
        int n=passingFees.size();
        vector<vector<pair<int,int>>>graph(n);
        for(auto x:edges)
        {
            graph[x[0]].push_back({x[1],x[2]});
            graph[x[1]].push_back({x[0],x[2]});
        }
        vector<vector<int>>dp(n,vector<int>(1001,-1));
        int ans=dfs(0,graph,maxTime,passingFees,dp);
        if(ans==INT_MAX)
            return -1;
        return ans;
    }
};
