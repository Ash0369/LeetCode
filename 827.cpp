class dsu
{
    public:
    vector<int>rank,parent,size;
    
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
    int largestIsland(vector<vector<int>>& grid) 
    {
        int n=grid.size();
        int ans=-1;//Whole grid is 1(assume)
        int dx[4]={-1,0,1,0};
        int dy[4]={0,1,0,-1};
        dsu ds(n*n);
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==1)
                {
                    for(int k=0;k<4;k++)
                    {
                        int nx=i+dx[k];
                        int ny=j+dy[k];
                        
                        if(nx>=0 && nx<n && ny>=0 && ny<n && grid[nx][ny]==1)
                            ds.union_by_size(ds.find_parent((n*j)+(i)),ds.find_parent((n*ny)+nx));
                        //ds.union_by_size((n*j)+(i),ds.find_parent((n*ny)+nx));//Use for reducing TC
                    }
                }
            }
        }
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==0)
                {
                    int counter=0;
                    set<int>st;
                    for(int k=0;k<4;k++)
                    {
                        int nx=i+dx[k];
                        int ny=j+dy[k];
                        
                        if(nx>=0 && nx<n && ny>=0 && ny<n && grid[nx][ny]==1)
                        {
                            st.insert(ds.find_parent(n*ny +nx));//As might be chance that any adjcent sides are already connected so we just take unique parents.
                        }
                    }
                    for(auto x:st)
                    {
                        counter+=ds.size[(x)];
                    }
                    ans=max(ans,counter+1);
                }
            }
        }
        if(ans==-1)
            return n*n;
        return ans;
    }
};
