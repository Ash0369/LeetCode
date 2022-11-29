void dfs(vector<vector<int>>&graph,int i,vector<int>&ans,vector<int>& quiet)
{
    ans[i]=i;
    for(auto x:graph[i])
    {
        if(ans[x]==-1)
            dfs(graph,x,ans,quiet);
        
        if(quiet[ans[i]]>quiet[ans[x]])
            ans[i]=ans[x];
    }
}
void toposort(vector<vector<int>>&graph,vector<int>&ans,int n,vector<int>& quiet)
{
    for(int i=0;i<n;i++)
    {
        if(ans[i]==-1)
        {
            dfs(graph,i,ans,quiet);
        }
    }
}
class Solution 
{
public:
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) 
    {
        int n=quiet.size();
        vector<vector<int>>gricher(n);
        
        //Same as Leet code -2392 but this time we will use DFS for toposort.
        
        for(auto x:richer)
        {
            gricher[x[1]].push_back(x[0]);
        }
        
        
        vector<int>ans(n,-1);
        toposort(gricher,ans,n,quiet);
        return ans;
        
    }
};
