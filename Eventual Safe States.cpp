class Solution 
{
  public:
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) 
    {
        int n=V;
        vector<vector<int>>graph(n);
        vector<int>indegree(n,0);
        for(int i=0;i<n;i++)
        {
            for(auto x:adj[i])
            {
                indegree[i]++;
                graph[x].push_back(i);
            }
        }
        
        queue<int>q;
        vector<int>dp;
        for(int i=0;i<n;i++)
        {
            if(indegree[i]==0)
            {
                q.push(i);
            }
        }
        
        while(!q.empty())
        {
            auto node=q.front();
            q.pop();
            dp.push_back(node);
            for(auto x:graph[node])
            {
                indegree[x]--;
                if(indegree[x]==0)
                {
                    q.push(x);
                }
            }
        }
        sort(dp.begin(),dp.end());
        return dp;
    }
};
