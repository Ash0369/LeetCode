int dfs(vector<vector<pair<int,int>>>&graph,int &n,vector<int>&shortt,vector<int>&dp,int i) 
{
    
    if (i == n)
        return 1;
    if(dp[i]!=-1)
        return dp[i];
   
    int ans=0;
    for (auto x : graph[i])
        if (shortt[i]>shortt[x.first])
            ans = (ans + dfs(graph,n,shortt,dp,x.first)) % 1000000007;
    
    
    return dp[i]=ans;
}

class Solution 
{
public:
    int countRestrictedPaths(int n, vector<vector<int>>& edges) 
    {
        vector<int>shortt(n+1,INT_MAX);
        vector<int>dp(n+1,-1);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        vector<vector<pair<int,int>>>graph(n+1);
        for(auto it:edges)
        {
            graph[it[0]].push_back({it[1],it[2]});
            graph[it[1]].push_back({it[0],it[2]});
        }
        pq.push({0,n});
        shortt[n]=0;
        while(!pq.empty())
        {
            auto node=pq.top();
            pq.pop();
            for(auto x:graph[node.second])
            {
                if(shortt[x.first]>x.second+node.first)
                {
                    shortt[x.first]=x.second+node.first;
                    pq.push({shortt[x.first],x.first});
                }
            }
        }
        return dfs(graph,n,shortt,dp,1);
        
        
    }
};
