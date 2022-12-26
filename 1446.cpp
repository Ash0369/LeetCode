int dfs(vector<vector<int>>&graph,int node,vector<bool>&dp)
{
    dp[node]=true;
    int cnt=0;
    for(auto x:graph[node])
    {
        if(dp[abs(x)]==false)
        {
            cnt+=dfs(graph,abs(x),dp)+(x>0);
        }
    }
    return cnt;
}
class Solution 
{
public:
    int minReorder(int n, vector<vector<int>>& connections) 
    {
        vector<bool>dp(n+1,false);
        vector<vector<int>>graph(n+1);
        for(auto x:connections)
        {
            graph[x[0]].push_back(x[1]);
            graph[x[1]].push_back(-1*x[0]);
        }
        return dfs(graph,0,dp);
    }
};
