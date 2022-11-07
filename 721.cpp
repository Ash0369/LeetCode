//Vey careful to use ds.find_parent , not use ds.parent[] because after last itertation of loop might parent are not updated.


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
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) 
    {
        int n=accounts.size();
        dsu ds(n);
        map<string,int>mp;
        for(int i=0;i<n;i++)
        {
            for(int j=1;j<accounts[i].size();j++)
            {
                if(mp.find(accounts[i][j])!=mp.end())
                {
                    ds.union_by_rank(ds.find_parent(i),ds.find_parent(mp[accounts[i][j]]));
                }
                else
                {
                    mp[accounts[i][j]]=i;
                }
            }
        }
   
        vector<string>words[n];
        for(auto x:mp)
        {
            int par=ds.find_parent(x.second);
            words[par].push_back(x.first);
        }
        
        vector<vector<string>>ans;
        for(int i=0;i<n;i++)
        {
            if(words[i].size()==0)
                continue;
            sort(words[i].begin(),words[i].end());
            vector<string>temp;
            temp.push_back(accounts[i][0]);
            
            for(auto it:words[i])
                temp.push_back(it);
            ans.push_back(temp);
        }
        return ans;
    }
};
