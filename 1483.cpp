vector<vector<int>>dp;
void binary_lifting(int curr,int parent,vector<vector<int>>&graph)
{
    
    dp[curr][0]=parent;
    for(int i=1;i<=19;i++)
    {
        int mid=dp[curr][i-1];
        if(mid!=-1)
        {
            dp[curr][i]=dp[mid][i-1];
        }
        else
        {
            dp[curr][i]=-1;
        }
    }
    for(auto x:graph[curr])
    {
        if(x!=parent)
        {
            binary_lifting(x,curr,graph);
        }
    }
}

int query(int node,int k)
{
    for(int i=19;i>=0;i--)
    {
        if(k==0 || node==-1)
        {
            break;
        }
        if(k>=(1<<i))
        {
            node=dp[node][i];
            k=k-(1<<i);
        }
    }
    return node;
}
class TreeAncestor 
{
public:
    TreeAncestor(int n, vector<int>& parent) 
    {
        vector<vector<int>>graph(n);
        dp.clear();
        dp.resize(n,vector<int>(20,-1));
        
        for(int i=0;i<n;i++)
        {
            if(parent[i]!=-1)
            {
                graph[parent[i]].push_back(i);
            }
            
        }
        
        binary_lifting(0,-1,graph);
    }
    
    int getKthAncestor(int node, int k) 
    {
        return query(node,k);
    }
};
