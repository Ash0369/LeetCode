//Method-1 : Brute Force --> Removing every edges and checking

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
        else if(rank[ultimate_parent_u]<rank[ultimate_parent_v])
        {
            parent[ultimate_parent_u]=ultimate_parent_v;
        }
        else if(rank[ultimate_parent_u]>rank[ultimate_parent_v])
        {
            parent[ultimate_parent_v]=ultimate_parent_u;
        }
        else if(rank[ultimate_parent_u]==rank[ultimate_parent_v])
        {
            parent[ultimate_parent_v]=ultimate_parent_u;
            rank[ultimate_parent_u]++;
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
        else if(size[ultimate_parent_u]<size[ultimate_parent_v])
        {
            parent[ultimate_parent_u]=ultimate_parent_v;
            size[ultimate_parent_v]+=size[ultimate_parent_u];
        }
        else if(size[ultimate_parent_u]>size[ultimate_parent_v])
        {
            parent[ultimate_parent_v]=ultimate_parent_u;
            size[ultimate_parent_u]+=size[ultimate_parent_v];
        }
        else if(size[ultimate_parent_u]==size[ultimate_parent_v])
        {
            parent[ultimate_parent_v]=ultimate_parent_u;
            size[ultimate_parent_u]+=size[ultimate_parent_v];
        }
    }
    
    void union_by_order(int u,int v)
    {
        int ultimate_parent_u=find_parent(u);
        int ultimate_parent_v=find_parent(v);

        if(ultimate_parent_u==ultimate_parent_v)
        {
            //They are belonging to same component
            return;
        }
        else if(ultimate_parent_u<ultimate_parent_v)
        {
            parent[ultimate_parent_v]=ultimate_parent_u;
        }
        else if(ultimate_parent_u>ultimate_parent_v)
        {
            parent[ultimate_parent_u]=ultimate_parent_v;
        }
        else if(ultimate_parent_u==ultimate_parent_v)
        {
            parent[ultimate_parent_v]=ultimate_parent_u;
        }
    }

};
class Solution 
{
public:
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) 
    {
        int n=edges.size();
        int ans;
        
        for(int i=0;i<n;i++)
        {
            bool res=true;
            //Excluding ith edge
            dsu ds(n+1);
            vector<int>indegree(n+1,0);
            for(int j=0;j<n;j++)
            {
                if(i==j)
                    continue;
                
                indegree[edges[j][1]]++;
                if(indegree[edges[j][1]]==2)
                {
                    res=false;
                    break;
                }
                ds.union_by_rank(edges[j][0],edges[j][1]);
            }
            
            if(res==true)
            {
                int cnt=0;
                for(int i=1;i<=n;i++)
                {
                    if(ds.find_parent(i)==i && cnt==1)
                    {
                        res=false;
                        break;
                    }
                    if(ds.find_parent(i)==i)
                    {
                        cnt++;
                    }
                }
            }
            if(res==true)
                ans=i;
        }
        return edges[ans];
    }
};
