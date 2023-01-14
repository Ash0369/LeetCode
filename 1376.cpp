int dfs(int node,int par,vector<int>&informTime,vector<vector<int>>&graph)
{
    int d=0;
    for(auto x:graph[node])
    {
        if(x!=par)
        {
            d=max(d,dfs(x,node,informTime,graph));
        }
    }
    return informTime[node]+d;
}
class Solution 
{
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) 
    {
        vector<vector<int>>graph(n);
        for(int i=0;i<n;i++)
        {
            if(manager[i]==-1)
                continue;
            graph[i].push_back(manager[i]);
            graph[manager[i]].push_back(i);
        }
        return dfs(headID,-1,informTime,graph);
    }
};
