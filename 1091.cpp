//Method-1 : Priority Queue

class Solution 
{
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) 
    {
        int n=grid.size();
        vector<vector<int>>distance(n,vector<int>(n,INT_MAX));
        
        distance[0][0]=0;
        
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        
        pq.push({0,{0,0}});
        
        int dx[8]={-1,0,1,0,-1,1,-1,1};
        int dy[8]={0,1,0,-1,1,1,-1,-1};
        bool iter=true;
        while(!pq.empty() && iter)
        {
            auto node=pq.top();
            pq.pop();
            
            int x=node.second.first;
            int y=node.second.second;
            
            int d=node.first;
            
            for(int i=0;i<8;i++)
            {
                int nx=x+dx[i];
                int ny=y+dy[i];
                
                if(nx>=0 && ny>=0 && nx<n && ny<n && grid[nx][ny]==0)
                {
                    int prevd=distance[nx][ny];
                    
                    if(prevd>(d+1))
                    {
                        distance[nx][ny]=d+1;
                        pq.push({d+1,{nx,ny}});
                    }
                    
                    if(nx==n-1 && ny==n-1)
                    {
                        iter=false;
                        break;
                    }
                }
            }
        }
        
        if(distance[n-1][n-1]==INT_MAX || grid[0][0]==1)
            return -1;
        return distance[n-1][n-1]+1;
    }
};


//Method-2 : Queue


class Solution 
{
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) 
    {
        int n=grid.size();
        if(n==1 && grid[0][0]==0)
            return 1;
        vector<vector<bool>>vis(n,vector<bool>(n,false));
        vis[0][0]=true;
        
        queue<pair<int,int>>q;
        
        q.push({0,0});
        
        int dx[8]={-1,0,1,0,-1,1,-1,1};
        int dy[8]={0,1,0,-1,1,1,-1,-1};
        bool iter=true;
        int d=0;
        while(!q.empty() && iter)
        {
            int len=q.size();
            for(int j=0;j<len;j++)
            {
                auto node=q.front();
                q.pop();
                
                int x=node.first;
                int y=node.second;
                for(int i=0;i<8;i++)
                {
                    int nx=x+dx[i];
                    int ny=y+dy[i];
                    
                    if(nx>=0 && ny>=0 && nx<n && ny<n && grid[nx][ny]==0 && vis[nx][ny]==false)
                    {
                        vis[nx][ny]=true;
                        q.push({nx,ny});
                        if(nx==n-1 && ny==n-1)
                        {
                            j=0;
                            iter=false;
                            break;
                        }
                    }
                }
            }
            d++;
        }
        
        if(vis[n-1][n-1]==false || grid[0][0]==1)
            return -1;
        return d+1;
    }
};
