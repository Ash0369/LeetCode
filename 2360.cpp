int cycle(int node,vector<vector<int>>&graph,vector<int>&vis,vector<int>&pvis,int len)
{
    int ans=-1;
    vis[node]=1;
    pvis[node]=len;
    for(auto x:graph[node])
    {
        if(vis[x]==1 && pvis[x]==-1)
        {
            continue;
        }
        if(vis[x]==1 && pvis[x]!=-1)
        {
            ans=max(ans,len+1-pvis[x]);
            continue;
        }
        ans=max(ans,cycle(x,graph,vis,pvis,len+1));
        
    }
    pvis[node]=-1;
    return ans;
}
class Solution 
{
public:
    int longestCycle(vector<int>& edges)
    {
        int ans=-1;
        int n=edges.size();
        vector<vector<int>>graph(n+1);
        for(int i=0;i<n;i++)
        {
            if(edges[i]==-1)
            {
                continue;
            }
            graph[i].push_back(edges[i]);
        }
        vector<int>vis(n+1,-1);
        vector<int>pvis(n+1,-1);
        for(int i=0;i<n;i++)
        {
            if(vis[i]==true)
            {
                continue;
            }
            ans=max(ans,cycle(i,graph,vis,pvis,0));
        }
        return ans;
    }
};
