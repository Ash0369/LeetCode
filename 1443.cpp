int dfs(int node,vector<vector<int>>&graph, vector<bool>& hasApple,vector<int>&dp)
{
    dp[node]=1;
    int cnt=0;
    for(auto x:graph[node])
    {
        if(dp[x]==1)
            continue;
        int a=dfs(x,graph,hasApple,dp);
        if(a!=-1)
        {
            cnt+=2+a;
        }
    }
    if(hasApple[node]==true)
    {
        return cnt;
    }
    else if(hasApple[node]==false && cnt>0)
    {
        return cnt;
    }
    
    return -1;
}
class Solution 
{
public:
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) 
    {
        vector<vector<int>>graph(n);
        vector<int>dp(n,-1);
        for(auto x:edges)
        {
            graph[x[0]].push_back(x[1]);
            graph[x[1]].push_back(x[0]);
        }
        return max(0,dfs(0,graph,hasApple,dp));
    }
};
