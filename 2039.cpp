class Solution 
{
public:
    int networkBecomesIdle(vector<vector<int>>& edges, vector<int>& patience) 
    {
        int n=patience.size();
        vector<vector<int>>graph(n);
        for(auto x:edges)
        {
            graph[x[0]].push_back(x[1]);
            graph[x[1]].push_back(x[0]);
        }
        vector<int>dp(n,INT_MAX);
        queue<pair<int,int>>q;
        q.push({0,0});
        while(!q.empty())
        {
            auto ele=q.front();
            q.pop();
            int node=ele.first;
            int d=ele.second;
            
            for(auto x:graph[node])
            {
                if(dp[x]>(d+1))
                {
                    dp[x]=d+1;
                    q.push({x,d+1});
                }
            }
        }
        int ans=0;
        for(int i=1;i<n;i++)
        {
            int time_to_reach=2*dp[i];
            int pt=patience[i];
            int d=time_to_reach%pt;
            d=((time_to_reach/pt)*pt);
            if(time_to_reach%pt==0)
                d=d-pt;
            ans=max(ans,d+time_to_reach+1);
        }
        return ans;
    }
};
