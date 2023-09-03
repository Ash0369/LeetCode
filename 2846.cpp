#define ll long long
class Tree
{
    public:
    vector<vector<vector<int>>>tree;
    vector<vector<int>>dp;
    vector<int>depth;
    vector<vector<int>>f;
    Tree(int n,vector<vector<int>>&edges)
    {
        tree.resize(n+2);
        dp.resize(n+2,vector<int>(30,0));
        f.resize(n+2,vector<int>(30,0));
        depth.resize(n+5,0);
        for(int i=0;i<n-1;i++)
        {
            int a,b,c;
            a=edges[i][0];
            b=edges[i][1];
            c=edges[i][2];
            tree[a].push_back({b,c});
            tree[b].push_back({a,c});
        }
    }
    void dfs(int index,int parent)
    {
        dp[index][0]=parent;
        if(parent!=-1)
        {
            depth[index]=depth[parent]+1;
        }
        else
        {
            depth[index]=0;
        }
        
        for(auto x:tree[index])
        {
            
            if(x[0]!=parent)
            {
                f[x[0]][x[1]]++;
                for(int i=1;i<=26;i++)
                {
                    f[x[0]][i]+=f[index][i];
                }
                dfs(x[0],index); 
            }
        }
    }
    void make_parent(int n)
    {
        for(int j=1;j<=29;j++)
        {
            for(int i=1;i<=n;i++)
            {
                int p=dp[i][j-1];
                if(p!=-1)
                {
                    dp[i][j]=dp[p][j-1];
                }
                else
                {
                    dp[i][j]=-1;
                }
            }
        }
    }
    int binary_lift(int node,int k)
    {
        int bit=0;
        while(k>0)
        {
            if((k&1)==1 && node!=-1)
            {
                node=dp[node][bit];
            }
            bit++;
            k=k>>1;
        }
        return node;
    }
    int lca(int u,int v)
    {
        int diff=abs(depth[u]-depth[v]);
        if(depth[u]>depth[v])
        {
            u=binary_lift(u,diff);
        }
        else if(depth[u]<depth[v])
        {
            v=binary_lift(v,diff);
        }
        if(u==v)
        {
            return u;
        }
        for(int i=29;i>=0;i--)
        {
            if(dp[u][i]==dp[v][i])
            {
                continue;
            }
            else
            {
                u=dp[u][i];
                v=dp[v][i];
            }
        }
        return dp[u][0];
    }
};
class Solution 
{
public:
    vector<int> minOperationsQueries(int n, vector<vector<int>>& edges, vector<vector<int>>& queries) 
    {
        Tree t(n,edges);
        t.dfs(0,-1);
        t.make_parent(n);
        vector<int>vp;
        cout<<t.f[0][1];
        for(auto x:queries)
        {
            int start=x[0];
            int end=x[1];
            int l=t.lca(start,end);
            vector<int>path(28,0);
            for(int i=1;i<=26;i++)
            {
                path[i]=t.f[start][i]+t.f[end][i]-(2*t.f[l][i]);
            }
            int tot=0;
            for(int i=1;i<=26;i++)
            {
                tot+=path[i];
            }
            int ans=1e8;
            
            for(int i=1;i<=26;i++)
            {
                ans=min(ans,tot-path[i]);
            }
            vp.push_back(ans);
        }
        return vp;
        
    }
};
