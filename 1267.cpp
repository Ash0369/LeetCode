//Method-1 : DSU

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
    int countServers(vector<vector<int>>& grid) 
    {
        int m=grid.size();
        int n=grid[0].size();
        dsu ds(m*n);
        int size=max(m,n);
        int row[size];
        int col[size];
        for(int i=0;i<size;i++)
        {
            row[i]=-1;
            col[i]=-1;
        }
        int ans=0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==0)
                    continue;
                if(row[i]!=-1)
                {
                    ds.union_by_size(row[i],(i*n)+j);
                }
                if(col[j]!=-1)
                {
                    ds.union_by_size(col[j],(i*n)+j);
                }
                row[i]=(i*n)+j;
                col[j]=(i*n)+j;
            }   
        }
        for(int i=0;i<(m*n);i++)
        {
            if(ds.parent[i]==i && ds.size[i]>1)
                ans=ans+ds.size[i];
        }
        return ans;
    }
};


//Method-2 : DFS

int dfs(int row,int col,int m,int n,vector<vector<int>>& grid,vector<vector<bool>>&dp)
{
    int cnt=0;
    //keep row constant and visit
    for(int j=0;j<n;j++)
    {
        if(dp[row][j]==false && grid[row][j]==1)
        {
            dp[row][j]=true;
            cnt++;
            cnt+=dfs(row,j,m,n,grid,dp);
        }
    }
    
    //keep col constant and visit
    for(int i=0;i<m;i++)
    {
        if(dp[i][col]==false && grid[i][col]==1)
        {
            dp[i][col]=true;
            cnt++;
            cnt+=dfs(i,col,m,n,grid,dp);
        }
    }
    return cnt;
}
class Solution 
{
public:
    int countServers(vector<vector<int>>& grid) 
    {
        int m=grid.size();
        int n=grid[0].size();
        int ans=0;
        vector<vector<bool>>dp(m,vector<bool>(n,false));
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(dp[i][j]==false && grid[i][j]==1)
                {
                    dp[i][j]=true;
                    int temp=dfs(i,j,m,n,grid,dp);
                    if(temp>0)
                        ans+=temp+1;
                    
                }
            }
        }
        return ans;
    }
};
