class Graph 
{
public:
    int num;
    vector<vector<pair<int,int>>>graph;
    Graph(int n, vector<vector<int>>& edges) 
    {
        num=n;
        graph.resize(n);
        for(auto x:edges)
        {
            graph[x[0]].push_back({x[1],x[2]});
        }
    }
    
    void addEdge(vector<int> edge) 
    {
        graph[edge[0]].push_back({edge[1],edge[2]});
    }
    
    int shortestPath(int node1, int node2) 
    {
        vector<int>dp(num+1,1e9);
        dp[node1]=0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push({0,node1});
        while(!pq.empty())
        {
            auto node=pq.top().second;
            if(node2==node)
            {
                return dp[node2];
            }
            int d=pq.top().first;
            pq.pop();
            for(auto x:graph[node])
            {
                if(dp[x.first]>(d+(x.second)))
                {
                    dp[x.first]=d+(x.second);
                    pq.push({dp[x.first],x.first});
                }
            }
            
        }
        return -1;
    }
};
