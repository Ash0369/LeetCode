class dsu
{
    vector<int>rank,parent,size;
    public:
    dsu(int n)
    {
        rank.resize(n+1,0);//Work for both 0 or 1 based
        parent.resize(n+1);
        size.resize(n+1);
        for(int i=0;i<=n;i++)
        {
            parent[i]=i;
            size[i]=1;
        }
    }

    int find_parent(int node)
    {
        if(node==parent[node])
        {
            return node;
        }
        return parent[node]=find_parent(parent[node]);//Path compression
    }

    void union_by_rank(int u,int v)
    {
        int ultimate_parent_u=find_parent(u);
        int ultimate_parent_v=find_parent(v);

        if(ultimate_parent_u==ultimate_parent_v)
        {
            //They are belonging to same component
            return;
        }
        else if(rank[ultimate_parent_u]<=rank[ultimate_parent_v])
        {
            parent[ultimate_parent_u]=ultimate_parent_v;
        }
        else if(rank[ultimate_parent_u]>rank[ultimate_parent_v])
        {
            parent[ultimate_parent_v]=ultimate_parent_u;
        }
    }

    void union_by_size(int u,int v)
    {
        int ultimate_parent_u=find_parent(u);
        int ultimate_parent_v=find_parent(v);

        if(ultimate_parent_u==ultimate_parent_v)
        {
            //They are belonging to same component
            return;
        }
        else if(size[ultimate_parent_u]<=size[ultimate_parent_v])
        {
            parent[ultimate_parent_u]=ultimate_parent_v;
            size[ultimate_parent_v]+=size[ultimate_parent_u];
        }
        else if(size[ultimate_parent_u]>size[ultimate_parent_v])
        {
            parent[ultimate_parent_v]=ultimate_parent_u;
            size[ultimate_parent_u]+=size[ultimate_parent_v];
        }
    }
};
class Solution 
{
public:
    bool validateBinaryTreeNodes(int n, vector<int>& lc, vector<int>& rc) 
    {
        dsu ds(n);
        vector<int>indegree(n,0);
        vector<int>tree(n,-1);
        for(int i=0;i<n;i++)
        {
            if(lc[i]!=-1)
            {
                ds.union_by_rank(i,lc[i]);
                indegree[i]++;
                tree[lc[i]]=i;
            }
            if(rc[i]!=-1)
            {
                ds.union_by_rank(i,rc[i]);
                indegree[i]++;
                tree[rc[i]]=i;
            }
        }
        set<int>st;
        for(int i=0;i<n;i++)
        {
            st.insert(ds.find_parent(i));
        }
        if(st.size()>1)
        {
            return false;
        }
        queue<int>q;
        vector<int>dp(n,0);
        for(int i=0;i<n;i++)
        {
            if(indegree[i]==0)
            {
                dp[i]=1;
                q.push(i);
            }
        }
        
        while(!q.empty())
        {
            int node=tree[q.front()];
            q.pop();
            if(node!=-1)
            {
                indegree[node]--;
                if(indegree[node]<0)
                {
                    return false;
                }
                if(indegree[node]==0)
                {
                    dp[node]=1;
                    q.push(node);
                }
            }
        }
        for(int i=0;i<n;i++)
        {
            if(dp[i]==0)
            {
                return false;
            }
        }
        return true;
    }
};
