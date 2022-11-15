#define pp pair<int,int>
class Solution 
{
public:
    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) 
    {
        vector<int>graph[n+1];
        for(int i=0;i<edges.size();i++)
        {
            graph[edges[i][0]].push_back(edges[i][1]);
            graph[edges[i][1]].push_back(edges[i][0]);
        }
        int dist[n+1];
        vector<pp>dp(n+1);
        for(int i=0;i<=n;i++)
        {
            dist[i]=INT_MAX;
        }
        dp[1]={1,0};//Node 1 visited at 1 time at time=0
        priority_queue<pp,vector<pp>,greater<pp>>pq;
        pq.push({0,1});
        while(!pq.empty())
        {
            int time_taken=pq.top().first;
            int node=pq.top().second;
            pq.pop();
            bool needWait = (time_taken / change) & 1;
            int waitTime = needWait ? (((time_taken / change) + 1) * change) - time_taken : 0;
            time_taken = time_taken + waitTime;
            
            for(auto it:graph[node])
            {
                if(dp[it].first<2 && dp[it].second!=time_taken+time)
                {
                    dp[it]={dp[it].first+1,time_taken+time};
                    pq.push({time_taken+time,it});
                    dist[it]=time_taken+time;
                }
            }
        }
        return dist[n];
    }
};
