bool dfs(int node,vector<int>adj[],vector<int>&visited,vector<int>&pvisited)
{
    visited[node]=true;
    pvisited[node]=true;
    for(auto x:adj[node])
    {
        if(pvisited[x]==true)
            return false;
        if(visited[x]==false)
        {
            if(dfs(x,adj,visited,pvisited)==false)
               return false;
        }
        
    }
    pvisited[node]=false;
    return true;
}
class Solution 
{
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) 
    {
        int n=numCourses;
        vector<int>visited(n,false);
        vector<int>pvisited(n,false);
        vector<int>adj[n];
        
        for(int i=0;i<prerequisites.size();i++)
        {
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        
        for(int i=0;i<n;i++)
        {
            if(visited[i]==false)
            {
                if(dfs(i,adj,visited,pvisited)==false)
                    return false;
            }
        }
        return true;
    }
};
