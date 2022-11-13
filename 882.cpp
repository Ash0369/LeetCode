class Solution 
{
public:
    int reachableNodes(vector<vector<int>>& edges, int maxMoves, int n) 
    {
        vector<vector<pair<int,int>>>graph(n);
        for(int i=0;i<edges.size();i++)
        {
            int u=edges[i][0];
            int v=edges[i][1];
            int cnt=edges[i][2];
            
            graph[u].push_back({v,cnt});
            graph[v].push_back({u,cnt});
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        int dp[n];
        for(int i=0;i<n;i++)
        {
            dp[i]=1e8;
        }
        
        pq.push({0,0});
        dp[0]=0;
        while(!pq.empty())
        {
            auto node=pq.top();
            pq.pop();
            int taken=node.first;
           
            for(auto it:graph[node.second])
            {
                int dest=it.first;
                if(dp[dest]>(taken+it.second+1))
                {
                    dp[dest]=taken+it.second+1;
                    pq.push({dp[dest],dest});
                }
            } 
        }
        int ans=0;
        
        for(int i=0;i<n;i++)
        {
            if(dp[i]<=maxMoves)
                ans++;
        }
        for(auto x:edges)
        {
            int u=x[0];
            int v=x[1];
            int nodes=x[2];
            
            int dist_left_at_u=max(0,maxMoves-dp[u]);
            int dist_left_at_v=max(0,maxMoves-dp[v]);

            if(dist_left_at_u+dist_left_at_v>=nodes)
                ans+=nodes;
            else
            {
                 ans+=dist_left_at_u+dist_left_at_v;
            }
        }
        return ans;
    }
};
