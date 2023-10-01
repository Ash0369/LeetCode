int dfs(int index,vector<int>&dp,vector<int>&ans,vector<vector<int>>&graph,int tme)
{
    dp[index]=tme;
    for(auto x:graph[index])
    {
        if(ans[x]!=-1)
        {
            ans[index]=ans[x]+1;
            return -1;
        }
        if(dp[x]==0)
        {
            int a=dfs(x,dp,ans,graph,tme+1);
            if(a==-1)
            {
                ans[index]=ans[x]+1;
                return -1;
            }
            else
            {
                ans[index]=ans[x];
                if(a!=index)
                {
                    return a;
                }
                else
                {
                    return -1;
                }
            }
            return a;
        }
        else
        {
            //cout<<index<<" "<<x<<" "<<dp[x]<<endl;
            ans[index]=tme-dp[x]+1;
            return x;
        }
    }
    return 0;
}
class Solution 
{
public:
    vector<int> countVisitedNodes(vector<int>& edges) 
    {
        int n=edges.size();
        vector<int>ans(n,-1);
        vector<vector<int>>graph(n+2);
        
        for(int i=0;i<n;i++)
        {
            graph[i].push_back(edges[i]);
        }
        vector<int>dp(n+5,0);
        for(int i=0;i<n;i++)
        {
            if(dp[i]==0)
            {
                dfs(i,dp,ans,graph,1);
            }
        }
        return ans;
    }
};
