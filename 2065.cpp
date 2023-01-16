int ans=0;
void dfs(int node,vector<int>& values, vector<vector<pair<int,int>>>&graph,int available, vector<bool>&vis,int score)
{
    if(node==0)
    {
        ans=max(ans,score);
    }
    for(auto x:graph[node])
    {
        if(available>=(x.second))
        {
            if(vis[x.first]==false)
            {
                vis[x.first]=true;
                dfs(x.first,values,graph,available-x.second,vis,score+values[x.first]);
                vis[x.first]=false;
            }
            else
                dfs(x.first,values,graph,available-x.second,vis,score);
            
        }
    }
}
class Solution 
{
public:
    int maximalPathQuality(vector<int>& values, vector<vector<int>>& edges, int maxTime) 
    {
        int n=values.size();
        vector<vector<pair<int,int>>>graph(n);
        ans=0;
        for(auto x:edges)
        {
            graph[x[0]].push_back({x[1],x[2]});
            graph[x[1]].push_back({x[0],x[2]});
        }
        vector<bool>vis(n,false);
        dfs(0,values,graph,maxTime,vis,0);
        return max(ans,values[0]);
    }
};
