//Method-1 : 

//We will connect all stones in same row and same col if by doing that let's say we have 4 set of stone in every set we can remove all stone except a single stone.

//Let's consider size of set as n1,n2..

//n1+n2..=n;

//Total reomove --> n1-1+n2-1... = n-(no of sets)
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
    int removeStones(vector<vector<int>>& stones) 
    {
        int n=stones.size();
        set<int>row;
        set<int>col; //To check whatever row,col already visited
        dsu ds(2*10000);//If all stones conneceted then max size
        int not_connected=0;
        for(auto it:stones)
        {
            int x=it[0];
            int y=it[1];
            
            if(row.find(x)==row.end() && col.find(y)==col.end())
                not_connected++;
            if(ds.find_parent(x)!=ds.find_parent(10000+y))
            {
                 
                 if(row.find(x)!=row.end() && col.find(y)!=col.end())
                 {
                     not_connected--;
                 }
                ds.union_by_size(x,10000+y);
            }
            row.insert(x);
            col.insert(y);   
        }
        return n-not_connected;
    }
};
