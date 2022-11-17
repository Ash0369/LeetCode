//Method-1 : Brute Force


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

#define pr pair<int,pair<int,int>>
class Solution 
{
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) 
    {
        dsu dsa(n+1);
        dsu dsb(n+1);
        priority_queue<pr>pq;
        for(auto x:edges)
        {
            pq.push({x[0],{x[1],x[2]}});
        }
        int ans=0;
        while(!pq.empty())
        {
            auto node=pq.top();
            pq.pop();
            int type=node.first;
            int u=node.second.first;
            int v=node.second.second;
            
            bool a=false;
            bool b=false;
            if(dsa.find_parent(u)==dsa.find_parent(v))
            {
                a=true;
            }
            if(dsb.find_parent(u)==dsb.find_parent(v))
            {
                b=true;
            }
            if(type==3)
            {
                if(a&&b)
                {
                    ans++;
                    continue;
                }
                dsa.union_by_size(u,v);
                dsb.union_by_size(u,v);
            }
            else
            {
               if(type==1)
               {
                   if(a)
                   {
                       ans++;
                       continue;
                   }
                   dsa.union_by_size(u,v);
               }
               else if(type==2)
               {
                   if(b)
                   {
                       ans++;
                       continue;
                   }
                   dsb.union_by_size(u,v);
               }
            }
        }
        int cnt=0;
        for(int i=1;i<=n;i++)
        {
            
            if(dsa.find_parent(i)==i)
                cnt++;
            if(dsb.find_parent(i)==i)
                cnt++;
        }
        if(cnt>2)
            return -1;
        return ans;
    }
};
