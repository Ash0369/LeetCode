class Solution 
{
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) 
    {
        vector<pair<double,int>>graph[n];
        for(int i=0;i<edges.size();i++)
        {
            graph[edges[i][0]].push_back({succProb[i],edges[i][1]});
            graph[edges[i][1]].push_back({succProb[i],edges[i][0]});
        }
        priority_queue<pair<double,int>>pq;
        vector<double>dp(n,-1.0);
        dp[start]=1;
        pq.push({1.0,start});
        while(!pq.empty())
        {
            auto node=pq.top();
            pq.pop();
            
            double probablity=node.first;
            int pos=node.second;
            
            for(auto x:graph[pos])
            {
                
                if(dp[x.second]<double(probablity*x.first))
                {
                    dp[x.second]=probablity*x.first;
                    pq.push({dp[x.second],x.second});
                }
            }
        }
        double ans=dp[end];
        if(ans==-1.0)
            return 0.0;
        
        return ans;
    }
};
