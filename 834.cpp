#define ll long long
vector<ll int>subtree;
vector<int>ans;
vector<ll int>no_node;
ll int N;
void dfs(ll int node,ll int parent,vector<vector<ll int>>&graph)
{
    ll int an=0;
    ll int nd=1;
    for(auto x:graph[node])
    {
        if(x==parent)
        {
            continue;
        }
        dfs(x,node,graph);
        an+=subtree[x]+no_node[x];
        nd+=no_node[x];
    }
    subtree[node]=an;
    no_node[node]=nd;
}
void calculate(ll int node,ll int parent,ll int partial,vector<vector<ll int>>&graph)
{
    ans[node]=subtree[node]+partial+N-no_node[node];
    for(auto x:graph[node])
    {
        if(x==parent)
        {
            continue;
        }
        ll int p=ans[node]-subtree[x]-no_node[x];
        calculate(x,node,p,graph);
    }
}class Solution 
{
public:
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) 
    {
        vector<vector<ll int>>graph(n+1);
        for(auto x:edges)
        {
            graph[x[0]].push_back(x[1]);
            graph[x[1]].push_back(x[0]);
        }
        subtree.clear();
        ans.clear();
        no_node.clear();
        subtree.resize(n,0);
        ans.resize(n,0);
        no_node.resize(n,0);
        dfs(0,-1,graph);
        N=no_node[0];
        ans[0]=subtree[0];
        calculate(0,-1,0,graph);
        return ans;
    }
};
