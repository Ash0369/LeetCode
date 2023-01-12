void merge(vector<int>&v1,vector<int>&v2)
{
    for(int i=0;i<26;i++)
        v1[i]+=v2[i];
}

vector<int> dfs(int node,vector<vector<int>>&graph,string &labels,vector<int>&counts, vector<int>&dp)
{
    dp[node]=1;
    vector<int>ans(26,0);
    ans[int(labels[node])-97]++;
    for(auto x:graph[node])
    {
        if(dp[x]==1)
            continue;
        auto y=dfs(x,graph,labels,counts,dp);
        merge(ans,y);
    }
    counts[node]=ans[int(labels[node])-97];
    return ans;
}
class Solution 
{
public:
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) 
    {
        vector<vector<int>>graph(n);
        for(auto x:edges)
        {
            graph[x[0]].push_back(x[1]);
            graph[x[1]].push_back(x[0]);
        }
        vector<int>counts(n,0);
        vector<int>dp(n,0);
        for(int i=0;i<n;i++)
        {
            if(dp[i]==0)
            {
                dfs(i,graph,labels,counts,dp);
            }
        }
        return counts;
    }
};
