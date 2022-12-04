class Solution 
{
public:
    int timer=1;
    void dfs(int node,int parent,vector<int>&vis,vector<int>&tin,vector<int>&low,vector<vector<int>>&bridges, vector<int>adj[])
    {
        vis[node]=1;
        tin[node]=timer;
        low[node]=timer;
        timer++;
        for(auto it:adj[node])
        {
            if(it==parent)
                continue;
            if(vis[it]==false)
            {
                dfs(it,node,vis,tin,low,bridges,adj);
                low[node]=min(low[node],low[it]);
                
                if(low[it]>tin[node])
                {
                    bridges.push_back({node,it});
                }
            }
            else
            {
                //If already Visited then it can never be bridge so just update low
                low[node]=min(low[node],low[it]);
            }
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) 
    {
        vector<int>adj[n];
        for(auto it:connections)
        {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        
        vector<int>vis(n,0);
        vector<int>tin(n);
        vector<int>low(n);
        vector<vector<int>>bridges;
        
        dfs(0,-1,vis,tin,low,bridges,adj);
        
        return bridges;
    }
};
