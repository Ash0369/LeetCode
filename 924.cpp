int dfs(int node, vector<vector<int>>&g,vector<bool>&dp)
{
    dp[node]=true;
    int cnt=0;
    for(auto x:g[node])
    {
        if(dp[x]==false)
        {
            cnt++;
            cnt+=dfs(x,g,dp);
        }
    }
    return cnt;
}

class Solution 
{
public:
    int minMalwareSpread(vector<vector<int>>& graph, vector<int>& initial) 
    {
      
        int n=graph.size();
        vector<vector<int>>g(n);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(graph[i][j]==1 && i!=j)
                {
                    g[i].push_back(j);
                    g[j].push_back(i);
                }
            }
        }
        int prev=INT_MAX;
        int ans=0;
        for(int i=0;i<initial.size();i++)
        {
            int cnt=0;
            vector<bool>dp(n+1,false);
            for(int j=0;j<initial.size();j++)
            {
                int ele=initial[j];
                if(i!=j && dp[ele]==false)
                {
                    cnt++;
                    cnt+=dfs(ele,g,dp);
                }
            };
            if(cnt<prev)
            {
                prev=cnt;
                ans=initial[i];
            }
            else if(cnt==prev)
            {
                ans=min(ans,initial[i]);
            }
        }
        return ans;
    }
};
