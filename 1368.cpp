//Using BFS

class Solution 
{
public:
    int minCost(vector<vector<int>>& grid) 
    {
        int m=grid.size();
        int n=grid[0].size();
        
       int dist[m][n];
       for(int i = 0; i<m; i++)
       {
            for(int j = 0; j<n; j++)
            {
                dist[i][j]=1e9;
            }
        }
        
        // priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        
        queue<pair<int,int>>pq;
        
        pq.push({0,0});
        dist[0][0]=0;
        int dx[4]={0,0,1,-1};//Right,left,down,up
        int dy[4]={1,-1,0,0};
        while(!pq.empty())
        {
            auto node=pq.front();
            pq.pop();
            int xc=node.first;
            int yc=node.second;
            int direction=grid[xc][yc];
            for(int i=0;i<4;i++)
            {
                int nx=xc+dx[i];
                int ny=yc+dy[i];
                
                if(nx>=0 && ny>=0 && nx<m && ny<n)
                {
                    int cost=1;
                    if(i+1==direction)
                        cost=0;
                    
                    if(dist[nx][ny]>cost+dist[xc][yc])
                    {
                        dist[nx][ny]=cost+dist[xc][yc];
                        pq.push({nx,ny});
                    }
                }
            }
            
        }
        return dist[m-1][n-1];
    }
};
