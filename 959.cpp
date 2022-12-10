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
    int regionsBySlashes(vector<string>& grid) 
    {
        int n=grid.size();
        
        dsu ds(((n+1)*(n+1))+1);
        int cnt=0;
        
        //All outer points are already connected
        for(int i=1;i<=(n+1);i++)
        {
            ds.union_by_rank(0,i);//All upper
            ds.union_by_rank(0,(n*(n+1))+i);//All lower
            ds.union_by_rank(1,(i*(n+1))+1);//All left
            ds.union_by_rank(1,(i*(n+1)));//All right
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==' ')
                    continue;
                
                int cor=(i*(n+1))+j+1;
                cout<<cor<<" ";
                if(grid[i][j]=='/')
                {
                    int start=cor+1;
                    int end=cor+n+1;
                    cout<<start<<" "<<end<<endl;
                    if(ds.find_parent(start)==ds.find_parent(end))
                        cnt++;
                    ds.union_by_rank(start,end);
                }
                else if(grid[i][j]=='\\')
                {
                    int start=cor;
                    int end=cor+n+2;
                    
                    if(ds.find_parent(start)==ds.find_parent(end))
                        cnt++;
                    ds.union_by_rank(start,end);
                }
            }
        }
        
        return cnt+1;//1 region is already there
    }
};
