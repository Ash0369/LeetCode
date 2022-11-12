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
    bool equationsPossible(vector<string>& equations) 
    {
        int n=equations.size();
        dsu ds(27);
        //First connect all equal ones and now if any point come where we have not equal and we connected it then return false
        for(int i=0;i<equations.size();i++)
        {
            int a=equations[i][0]-97;
            int b=equations[i][3]-97;
            
            int x=equations[i][1];
            
            if(x=='=')
            {
               ds.union_by_size(a,b);
            } 
        }
        for(int i=0;i<equations.size();i++)
        {
            int a=equations[i][0]-97;
            int b=equations[i][3]-97;
            
            int x=equations[i][1];
            
            if(x=='!')
            {
               if(ds.find_parent(a)==ds.find_parent(b))
                   return false;
            } 
        }
        return true;
    }
};
