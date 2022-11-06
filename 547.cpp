//Method-1 : BFS


class Solution 
{
public:
    int findCircleNum(vector<vector<int>>& isConnected) 
    {
        int n=isConnected.size();
        vector<int>visited(n,0);
        int count=0;
        for(int i=0;i<n;i++)
        {
            if(!visited[i])
            {
                queue<int>q;
                q.push(i);
                visited[i]=1;
                int j=0;
                while(!q.empty())
                {
                    int node=q.front();
                    q.pop();
                    for(int i=0;i<n;i++)
                    {
                        int x=isConnected[node][i];
                        if(x==1 && !visited[i])
                        {
                            q.push(i);
                            visited[i]=1;
                        }
                    }
                }
                count++;
            }
        }
        return count;
    }
};


//Method-2 : DFS

class Solution 
{
public:
    int cnt=0;
    void dfs(vector<vector<int>>&m,int i,vector<bool>&vis)
    {
        vis[i]=true;
        for(int j=0;j<m.size();j++)
        {
            if(m[i][j]==1 && vis[j]==false)
            {
                dfs(m,j,vis);
            }
            
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) 
    {
        int n=isConnected.size();
        vector<bool>vis(n+1,false);
        for(int i=0;i<n;i++)
        {
            if(vis[i]==false)
            {
                cnt++;
                dfs(isConnected,i,vis);
            }
        }
        
        return cnt;
    }
};


//Method-3 : DSU

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
    int findCircleNum(vector<vector<int>>& isConnected) 
    {
        int n=isConnected.size();
        dsu ds(n);
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(isConnected[i][j]==1)
                {
                    ds.union_by_rank(i,j);
                }
            }
        }
        
        int cnt=0;
        for(int i=0;i<n;i++)
        {
            if(ds.parent[i]==i)
                cnt++;
        }
        return cnt;
    }
};
