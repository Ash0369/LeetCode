bool dfs(int node,int color,vector<int>&ans,vector<vector<int>>&graph)
{
    for(auto x:graph[node])
    {
        if(ans[x]==color)
            return false;
    }
    for(auto x:graph[node])
    {
        if(ans[x]==0)
        {
            for(int i=1;i<=4;i++)
            {
                if(i==color)
                    continue;
                ans[x]=i;
                if(dfs(x,ans[x],ans,graph))
                    break;
            }
        } 
    }
    return true;
}
class Solution 
{
public:
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) 
    {
        vector<vector<int>>graph(n);
        for(auto x:paths)
        {
            graph[x[0]-1].push_back(x[1]-1);
            graph[x[1]-1].push_back(x[0]-1);
        }
        
        vector<int>ans(n,0);
        for(int i=0;i<n;i++)
        {
            if(ans[i]==0)
            {
                ans[i]=1;
                dfs(i,1,ans,graph);
            }
        }
        return ans;
    }
};
