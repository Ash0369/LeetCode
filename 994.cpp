#define mp(a,b) make_pair(a,b)
class Solution 
{
public:
    int orangesRotting(vector<vector<int>>& grid) 
    {
        int m=grid.size();
        int n=grid[0].size();
        
        queue<pair<int,int>>q;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==2)
                {
                    q.push(mp(i,j));
                }
            }
        }
        vector<int>dx={-1,0,1,0};
        vector<int>dy={0,1,0,-1};
        int time=0;
        while(!q.empty())
        {
            int k=q.size();
            time++;
            
            for(int i=0;i<k;i++)
            {
                int x=q.front().first;
                int y=q.front().second;
                q.pop();
                
                for(int j=0;j<4;j++)
                {
                    int nx=x+dx[j];
                    int ny=y+dy[j];
                    
                    if(nx>=0 && nx<m && ny>=0 && ny<n && grid[nx][ny]==1)
                    {
                        q.push(mp(nx,ny));
                        grid[nx][ny]=2;
                    }
                }
            }
        }
        
        for(auto x:grid)
        {
            for(auto y:x)
            {
                if(y==1)
                    return -1;
            }
        }
        return max(0,time-1);
    }
};
