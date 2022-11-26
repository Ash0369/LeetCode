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


bool cmp(vector<int>&x1,vector<int>&x2)
{
    if(x1[2]<x2[2])
        return true;
    return false;
}


class Solution 
{
public:
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) 
    {
        vector<int>critical;
        vector<int>pseudeo_critical;
        
        //We will sort the edges so we will loose the orginal postion so we are pushing it back to use in the future.
        for(int i=0;i<edges.size();i++)
        {
            edges[i].push_back(i);
        }
        //We will keep edges with minimum length at top.
        sort(edges.begin(),edges.end(),cmp);
        //We will keep track which element included in MST.
        vector<bool>dp(edges.size(),false);
        dsu ds(n);
        int min_cost=0;
        //Making Mst and edges we are using marking them as true.
        for(int i=0;i<edges.size();i++)
        {
            int a=edges[i][0];
            int b=edges[i][1];
            
            if(ds.find_parent(a)==ds.find_parent(b))
                continue;
            ds.union_by_size(a,b);
            dp[i]=true;
            min_cost+=edges[i][2];
        }
        
        //Checking Crtical edges.
        for(int i=0;i<edges.size();i++)
        {
            if(dp[i]==true)
            {
                //Included in MST this edge so we will try to form MST exculding this edge.
                dsu ds(n);
                int cost=0;
                for(int j=0;j<edges.size();j++)
                {
                    if(i==j)
                        continue;//We not have to include this edge
                    
                    int a=edges[j][0];
                    int b=edges[j][1];
                    
                    if(ds.find_parent(a)==ds.find_parent(b))
                        continue;
                    
                    ds.union_by_size(a,b);
                    cost+=edges[j][2];
                }
                
                if(cost>min_cost || cost<min_cost)
                {
                    //Crtical edge as cost increase then cost of Mst and if cost decreases that means it not able to form Mst
                    critical.push_back(edges[i][3]);
                }
                else
                {
                    //If not crtical edge then mark it as true we will check for psudeo edge for this.
                    dp[i]=false;
                }
            }
        }
        
        
        for(int i=0;i<edges.size();i++)
        {
            if(dp[i]==false)
            {
                //We will try to inlude this edge and form Mst if we able to form then Psudeo Crtical other wise not.
                dsu ds(n);
                int cost=0;
                //Must including Edge i
                int a=edges[i][0];
                int b=edges[i][1];
                ds.union_by_size(a,b);
                cost+=edges[i][2];
                    
                for(int j=0;j<edges.size();j++)
                {
                    int a=edges[j][0];
                    int b=edges[j][1];
                    
                    if(ds.find_parent(a)==ds.find_parent(b))
                        continue;
                    
                    ds.union_by_size(a,b);
                    cost+=edges[j][2];
                }
                
                if(cost==min_cost)
                {
                    //We able to form Mst so it is Psudeo Critical edge.
                    pseudeo_critical.push_back(edges[i][3]);
                }
            }
        }
        
        vector<vector<int>>ans;
        ans.push_back(critical);
        ans.push_back(pseudeo_critical);
        
        return ans;
        
    }
};
