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
        
        for(int i=n-1;i>=0;i--)
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
            {
                ans=i;
                break;
            }
        }
        return edges[ans];
    }
};


//Method-2 : Optimized 
//https://www.youtube.com/watch?v=d0tqBMRZ6UQ&t=893s

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
        vector<int>indegree(n+1,-1);
        int blacklist1=-1;
        int blacklist2=-1;
        dsu ds(n+1);
        
        for(int j=0;j<n;j++)
        {
            int u=edges[j][0];
            int v=edges[j][1];
            
            if(indegree[v]==-1)
            {
                indegree[v]=j;
            }
            else
            {
                blacklist1=j;//Which is now give extra indegree
                blacklist2=indegree[v];//Which already given indegree;
                break;
            }
            
        }
        
        for(int i=0;i<n;i++)
        {
            if(i==blacklist1)
                continue;
            
            int u=edges[i][0];
            int v=edges[i][1];
            if(ds.find_parent(u)==ds.find_parent(v))
            {
                if(blacklist1==-1)
                {
                    //We don't have any blacklist edge but then also cycle.
                    //So cureent ith edge we have to remove
                    
                    return edges[i];
                }
                //We already skipped blacklist1 edge then also cycle is present.
                //So we have to remove backlist2
                
                return edges[blacklist2];
            }
            ds.union_by_rank(u,v);
        }
        
        //We have reached here means we have correctly blacklisted1
        return edges[blacklist1];
    }
};
