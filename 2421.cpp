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
    
    int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) 
    {
        int n=vals.size();
        dsu ds(n);
        vector<vector<int>>graph(n);
        map<int,vector<int>>mp;
        for(int i=0;i<n;i++)
        {
            mp[vals[i]].push_back(i);
        }
        for(auto x:edges)
        {
            if(vals[x[1]]<=vals[x[0]])
               graph[x[0]].push_back(x[1]);
            if(vals[x[0]]<=vals[x[1]])
               graph[x[1]].push_back(x[0]);
        }
        int good=0;
        for(auto x:mp)
        {
            for(auto node:x.second)
            {
                for(auto neighbour:graph[node])
                {
                    ds.union_by_rank(node,neighbour);
                }
            }
            
            unordered_map<int,int>nmp;
            
            for(auto node:x.second)
            {
                nmp[ds.find_parent(node)]++;
                //It will give us number of group
            }
            
            //All good paths from node to itself
            
            good+=x.second.size();
            
            for(auto x:nmp)
            {
                if(x.second>1)
                {
                    //There more then 1 element of this value present in the same grp
                    //So choose any 2 to it will give a path so nc2
                    int sz=x.second;
                    good+=(sz*(sz-1))/2;
                }
            }
            
        }
        
        return good;
    }
};
