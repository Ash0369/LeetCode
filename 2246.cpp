int mx=1;
void adjst(int &mx1,int &mx2,int num)
{
    if(num>=mx1)
    {
        swap(mx1,mx2);
        mx1=num;
    }
    else if(num>mx2)
    {
        mx2=num;
    }
}
int dfs(int node,vector<vector<int>>&graph,string &s)
{
    int mx1=0;
    int mx2=0;
    for(auto x:graph[node])
    {
        if(s[x]!=s[node])
        {
            int cnt=dfs(x,graph,s);
            adjst(mx1,mx2,cnt);
        }
        else
        {
            int cnt=dfs(x,graph,s);
            mx=max(mx,cnt);
        }
    }
    mx=max(mx,mx1+mx2+1);
    mx=max(mx1+1,mx);
    return mx1+1;
}
class Solution 
{
public:
    int longestPath(vector<int>& parent, string s) 
    {
        mx=1;
        int n=parent.size();
        vector<vector<int>>graph(n);
        for(int i=0;i<n;i++)
        {
            if(parent[i]==-1)
                continue;
            graph[parent[i]].push_back(i);
        }
        dfs(0,graph,s);
        return mx; 
    }
};
