vector<int>dfs(int node,vector<vector<int>>&graph,string &s,vector<vector<int>>&dp)
{
    if(dp[node].size()>0)
    {
        return dp[node];
    }
    vector<int>p(26,0);
    for(auto x:graph[node])
    {
     
        vector<int>ans=dfs(x,graph,s,dp);
        for(int i=0;i<26;i++)
        {
            p[i]=max(p[i],ans[i]);
        }
    }
    p[int(s[node])-97]++;
    return dp[node]=p;
}
class Solution 
{
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) 
    {
        int n=colors.size();
        vector<vector<int>>graph(n+1);
        vector<int>indegree(n,0);
        vector<vector<int>>dp(n);
        for(auto x:edges)
        {
            graph[x[0]].push_back(x[1]);
            indegree[x[1]]++;
        }
        queue<int>pq;
        for(int i=0;i<n;i++)
        {
            if(indegree[i]==0)
            {
                pq.push(i);
            }
        }
        int cnt=0;
        while(!pq.empty())
        {
            cnt++;
            int ele=pq.front();
            pq.pop();
            for(auto x:graph[ele])
            {
                indegree[x]--;
                if(indegree[x]==0)
                {
                    pq.push(x);
                }
            }
        }
        if(cnt!=n)
        {
            return -1;
        }
        int ans=0;
        for(int i=0;i<n;i++)
        {
            
            if(dp[i].size()>0)
            {
                continue;
            }
           
            dfs(i,graph,colors,dp);
            for(int j=0;j<26;j++)
            {
                ans=max(ans,dp[i][j]);
            }
        }
        return ans;
        
    }
};
