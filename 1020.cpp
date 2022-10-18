#define mp(a,b) make_pair(a,b)
class Solution
{
public:
    int numEnclaves(vector<vector<int>>& grid) 
    {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<bool>>vis(m,vector<bool>(n,false));
        
        queue<pair<int,int>>q;
        
        for(int i=0;i<m;i++)
        {
            
            if(grid[i][0]==1)
            {
                q.push(mp(i,0));
                vis[i][0]=true;
            }
            if(grid[i][n-1]==1)
            {
                q.push(mp(i,n-1));
                vis[i][n-1]=true;
            }
            
        }
        
        for(int i=0;i<n;i++)
        {
            
            if(grid[0][i]==1)
            {
                q.push(mp(0,i));
                vis[0][i]=true;
            }
            if(grid[m-1][i]==1)
            {
                q.push(mp(m-1,i));
                vis[m-1][i]=true;
            }
            
        }
        
        
        vector<int>dx={-1,0,1,0};
        vector<int>dy={0,1,0,-1};
        
        while(!q.empty())
        {
            int x=q.front().first;
            int y=q.front().second;
            q.pop();
            
            for(int j=0;j<4;j++)
            {
                int nx=x+dx[j];
                int ny=y+dy[j];
                
                if(nx>=0 && ny>=0 && nx<m && ny<n)
                {
                    if(grid[nx][ny]==1 && vis[nx][ny]==false)
                    {
                        q.push(mp(nx,ny));
                        vis[nx][ny]=true;
                    }
                }       
            }  
        }
        int cnt=0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==1 && vis[i][j]==false)
                    cnt++;
            }
        }
        return cnt;
    }
};
