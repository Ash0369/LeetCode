//Method-1 : Will give TLE

//In this we will start from back and as we are getting water we will marking it in grid and will connect all surrounding water and if at any point we able to connect 
//Top most layer to down layer that will be our last point from the starting.


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
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) 
    {
        dsu ds(row*col+1);
        int n=cells.size();
        vector<vector<int>>grid(row+1,vector<int>(col+1,0));
        int dx[4]={-1,0,1,0};
        int dy[4]={0,1,0,-1};
        
        for(int i=n-1;i>=0;i--)
        {
            int p=cells[i][1]+(col*(cells[i][0]-1));
            grid[cells[i][0]][cells[i][1]]=1;
            for(int j=0;j<4;j++)
            {
                int nx=cells[i][0]+dx[j];
                int ny=cells[i][1]+dy[j];
                
                if(nx>=1 && nx<=row && ny>=1 && ny<=col && grid[nx][ny]==1)
                {
                    int np=ny+(col*(nx-1));
                    ds.union_by_rank(p,np);
                }
                
            }
            for(int j=1;j<=col;j++)
            {
                for(int k=(col*(row-1))+1;k<=row*col;k++)
                {
                    if(ds.find_parent(j)==ds.find_parent(k))
                    {
                        return i;
                    }
                }
            }
        }
        return 1;
    }
};


//Method-2 : 
//In this we will try to optimize Method-1 , in method-1 we are doing union by rank that's why we have to iterate over all cells of top and all cells of bottom
//To avoid that we can use union by order in this we will make parent always smaller one , now after every iteration we will just check that parent of any bottom
//cell is less then col or not (which is top row) like these we have converted O(col*col) Loop to O(col).

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
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) 
    {
        dsu ds(row*col+1);
        int n=cells.size();
        vector<vector<int>>grid(row+1,vector<int>(col+1,0));
        int dx[4]={-1,0,1,0};
        int dy[4]={0,1,0,-1};
        
        for(int i=n-1;i>=0;i--)
        {
            int p=cells[i][1]+(col*(cells[i][0]-1));
            grid[cells[i][0]][cells[i][1]]=1;
            for(int j=0;j<4;j++)
            {
                int nx=cells[i][0]+dx[j];
                int ny=cells[i][1]+dy[j];
                
                if(nx>=1 && nx<=row && ny>=1 && ny<=col && grid[nx][ny]==1)
                {
                    int np=ny+(col*(nx-1));
                    ds.union_by_order(p,np);
                }
                
            }
           
            for(int k=(col*(row-1))+1;k<=row*col;k++)
            {
                if(ds.find_parent(k)<=col)
                {
                    return i;
                }
            } 
        }
        return 1;
    }
};



//Method-3 : Binary search


bool able_to_cross(int curr,vector<vector<int>>& cells,int row,int col)
{
    vector<vector<int>>vec(row+1,vector<int>(col+1,0));
    for(int i=0;i<curr;i++)
    {
        vec[cells[i][0]][cells[i][1]]=1;//Marked Visited
    }
    queue<pair<int,int>>q;
    int dx[4]={-1,0,1,0};
    int dy[4]={0,1,0,-1};
    for(int i=1;i<=col;i++)
    {
        if(vec[1][i]==0)
        {
            vec[1][i]=1;
            q.push({1,i});//Pushing top row
        }
    }
    while(!q.empty())
    {
        int x=q.front().first;
        int y=q.front().second;
        if(x==row)
            return true;
        q.pop();
        for(int i=0;i<4;i++)
        {
            int nx=x+dx[i];
            int ny=y+dy[i];
            
            if(nx>=1 && ny>=1 && nx<=row && ny<=col && vec[nx][ny]==0)
            {
                vec[nx][ny]=1;
                q.push({nx,ny});
            }
        }
    }
    return false;
}
class Solution 
{
public:
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) 
    {
        int low=0;
        int high=cells.size();
        int ans=0;
        while(low<=high)
        {
            int mid=(low+high)/2;
            if(able_to_cross(mid,cells,row,col))
            {
                ans=max(ans,mid);
                low=mid+1;
            }
            else
            {
                high=mid-1;
            }
        }
        return ans;
    }
};
