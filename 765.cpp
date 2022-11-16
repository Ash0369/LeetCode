//Method-1 : DFS

int dfs(int start,vector<int>&row)
{
    int ele=row[start];
    for(int i=start+1;i<row.size();i++)
    {
        int nele=row[i];
        if(nele==ele+1 && ele%2==0)
        {
            if(i==start+1)
                return 0;
            swap(row[start+1],row[i]);
            return 1;
        }
        if(nele+1==ele && ele%2!=0)
        {
            if(i==start+1)
                return 0;
            swap(row[start+1],row[i]);
            return 1;
        }
        
    }
    return 0;
}
class Solution 
{
public:
    int minSwapsCouples(vector<int>& row) 
    {
        int ans=0;
        for(int i=0;i<row.size();i++)
        {
            int a=dfs(i,row);
            ans+=a;
        }
        return ans;
    }
};


//Method-2 : DSU

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
    int minSwapsCouples(vector<int>& row) 
    {
        int ans=0;
        dsu ds(row.size()+1);
        for(int i=0;i<row.size();i=i+2)
        {
            ds.union_by_rank(row[i],row[i+1]);
        }
        for(int i=0;i<row.size();i=i+2)
        {
            if(ds.find_parent(i)!=ds.find_parent(i+1))
            {
                ans++;
                ds.union_by_rank(i,i+1);
            }
        }
        return ans;
    }
};
