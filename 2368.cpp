//Method-1 : 

int dfs(int node,vector<vector<int>>&graph,vector<bool>&dp,set<int>&r)
{
    int cnt=1;
    dp[node]=true;
    for(auto x:graph[node])
    {
        if(dp[x]==false && r.find(x)==r.end())
        {
            cnt+=dfs(x,graph,dp,r);
        }
    }
    return cnt;
}
class Solution 
{
public:
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) 
    {
        vector<vector<int>>graph(n);
        set<int>r(restricted.begin(),restricted.end());
        vector<bool>dp(n+1,false);
        for(auto x:edges)
        {
            graph[x[0]].push_back(x[1]);
            graph[x[1]].push_back(x[0]);
        }
        if(r.find(0)!=r.end())
            return 0;
        return dfs(0,graph,dp,r);
    }
};


//Method-2 : 

int dfs(int node,vector<vector<int>>&graph,vector<bool>&dp,vector<bool>&r)
{
    int cnt=1;
    dp[node]=true;
    for(auto x:graph[node])
    {
        if(dp[x]==false && r[x]==false)
        {
            cnt+=dfs(x,graph,dp,r);
        }
    }
    return cnt;
}
class Solution 
{
public:
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) 
    {
        vector<vector<int>>graph(n);
        vector<bool>r(n,false);
        for(auto x:restricted)
            r[x]=true;
        vector<bool>dp(n+1,false);
        for(auto x:edges)
        {
            graph[x[0]].push_back(x[1]);
            graph[x[1]].push_back(x[0]);
        }
        if(r[0]==true)
            return 0;
        return dfs(0,graph,dp,r);
    }
};
