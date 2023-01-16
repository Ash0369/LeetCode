int mini=INT_MAX;
void dfs(int node,vector<int>&dp,vector<vector<pair<int,int>>>&graph)
{
    dp[node]=1;
    int ans=-1;
    for(auto x:graph[node])
    {
        mini=min(mini,x.second); 
        if(dp[x.first]==0)
        {
            dfs(x.first,dp,graph);
        }
    }
}

class Solution 
{
public:
    int minScore(int n, vector<vector<int>>& roads) 
    {
        vector<vector<pair<int,int>>>graph(n+1);
        for(auto x:roads)
        {
            graph[x[0]].push_back({x[1],x[2]});
            graph[x[1]].push_back({x[0],x[2]});
        }
        vector<int>dp(n+1,0);
        mini=INT_MAX;
        dfs(1,dp,graph);
        return mini;
    }
};
