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

};


class Solution 
{
public:
    bool hasValidPath(vector<vector<int>>& grid) 
    {
        int m=grid.size();
        int n=grid[0].size();
        
        dsu ds(m*n);
        
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {

                int g=grid[i][j];
                if(g==1)
                {
                    
                    if(j+1<n && grid[i][j+1]%2!=0)
                        ds.union_by_size(i*n+j,(i)*n+(j+1));
                    if(j-1>=0 && (grid[i][j-1]%2==0 || grid[i][j-1]==1))
                        ds.union_by_size(i*n+j,(i)*n+(j-1));
                }
                else if(g==2)
                {
                    if(i+1<m && (grid[i+1][j]==5 || grid[i+1][j]==6))
                        ds.union_by_size(i*n+j,(i+1)*n+(j));
                    if(i-1>=0 &&  (grid[i-1][j]==4 || grid[i-1][j]==3 || grid[i-1][j]==2))
                        ds.union_by_size(i*n+j,(i-1)*n+j);
                }
                else if(g==3)
                {
                    if(i+1<m && (grid[i+1][j]==5 || grid[i+1][j]==6))
                        ds.union_by_size(i*n+j,(i+1)*n+(j));
                    if(j-1>=0 &&  (grid[i][j-1]%2==0 || grid[i][j-1]==1))
                        ds.union_by_size(i*n+j,(i)*n+(j-1));
                }
                else if(g==4)
                {
                    if(i+1<m && (grid[i+1][j]==5 || grid[i+1][j]==6))
                        ds.union_by_size(i*n+j,(i+1)*n+j);
                    if(j+1<n && grid[i][j+1]%2!=0)
                        ds.union_by_size(i*n+j,(i)*n+(j+1));
                }
                else if(g==5)
                {
                    if(i-1>=0 && (grid[i-1][j]==4 || grid[i-1][j]==3 || grid[i-1][j]==2))
                        ds.union_by_size(i*n+j,(i-1)*n+j);
                    if(j-1>=0 && (grid[i][j-1]%2==0 || grid[i][j-1]==1))
                        ds.union_by_size(i*n+j,(i)*n+(j-1));
                }
                else if(g==6)
                {
                    if(j+1<n && grid[i][j+1]%2!=0)
                        ds.union_by_size(i*n+j,i*n+(j+1));
                    if(i-1>=0 && (grid[i-1][j]==4 || grid[i-1][j]==3 || grid[i-1][j]==2))
                        ds.union_by_size(i*n+j,(i-1)*n+j);
                }
                                 
            }
        }
        
        if(ds.find_parent(m*n -1)==ds.find_parent(0))
            return true;
        return false;
    }
};
