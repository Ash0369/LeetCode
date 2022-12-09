void dfs(vector<vector<int>>& graph,int curr,vector<vector<int>>&ans,vector<int>&s)
{
    int n=graph.size();
    for(auto x:graph[curr])
    {
        if(x==n-1)
        {
            s.push_back(n-1);
            ans.push_back(s);
            s.pop_back();
            continue;
        }
        s.push_back(x);
        dfs(graph,x,ans,s);
        s.pop_back();
    }
}
class Solution 
{
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) 
    {
        int n=graph.size();
        int cnt=0;
        vector<int>vec;
        vector<vector<int>>ans;
        vec.push_back(0);
        dfs(graph,0,ans,vec);
        return ans;
     
    }
};
