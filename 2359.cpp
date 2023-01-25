int nde;
int cst;
void dfs(vector<int>&edges,int node,vector<bool>&vis,vector<int>&cost,int curr)
{
    vis[node]=true;
    if(cost[node]!=-1)
    {
        int temp=max(cost[node],curr);
        if(cst>temp)
        {
            cst=temp;
            nde=node;
        }
        else if(cst==temp && nde>node)
            nde=node;
    }
    cost[node]=curr;
    if(edges[node]==-1 || vis[edges[node]]==true)
        return;
    dfs(edges,edges[node],vis,cost,curr+1);
}
class Solution 
{
public:
    int closestMeetingNode(vector<int>& edges, int node1, int node2) 
    {
        int n=edges.size();
        nde=-1;
        cst=INT_MAX;
        
        vector<bool>vis(n,false);
        vector<int>cost(n,-1);
        dfs(edges,node1,vis,cost,0);
        vector<bool>vis2(n,false);
        dfs(edges,node2,vis2,cost,0);
        
        return nde;
    }
};
