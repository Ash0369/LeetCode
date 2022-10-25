//Method-1 : DFS

bool dfs(int node,vector<bool>&vis, vector<bool>&pvis,vector<vector<int>>&adj,  vector<int>&check)
{
    vis[node]=true;
    pvis[node]=true;
    
    for(auto x:adj[node])
    {
        if(vis[x]==true && pvis[x]==true)
        {
            return true;
        }
        else if(vis[x]==false)
        {
            vis[x]=true;
            pvis[x]=true;
            if(dfs(x,vis,pvis,adj,check)==true)
            {
                return true;
            }
            pvis[x]=false;
        }
    }
    check[node]=1;
    pvis[node]=false;
    return false;
}

class Solution 
{
public:
    vector<int> eventualSafeNodes(vector<vector<int>>&adj) 
    {
        int v=adj.size();
        vector<bool>vis(v+1,false);
        vector<bool>pvis(v+1,false);
        vector<int>check(v+1,false);
        vector<int>safe;
        for(int i=0;i<v;i++)
        {
            dfs(i,vis,pvis,adj,check);
        }
        
        for(int i=0;i<=v;i++)
        {
            if(check[i]==1)
                safe.push_back(i);
        }
        
        return safe;
    }
};


//Method-2 : BFS

class Solution 
{
public:
    vector<int> eventualSafeNodes(vector<vector<int>>&adj) 
    {
        int n=adj.size();
        vector<int>adjrev[n];
        vector<int>indegree(n,0);
        for(int i=0;i<n;i++)
        {
            for(auto it:adj[i])
            {
                adjrev[it].push_back(i);
                indegree[i]++;
            }
        }
        
        queue<int>q;
        for(int i=0;i<n;i++)
        {
            if(indegree[i]==0)
                q.push(i);
        }
        vector<int>ans;
        
        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            ans.push_back(node);
            for(auto x:adjrev[node])
            {
                indegree[x]--;
                if(indegree[x]==0)
                {
                    q.push(x);
                }
            }
        }
        
        sort(ans.begin(),ans.end());
        return ans;
    }
};
