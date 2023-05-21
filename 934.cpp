int dx[4]={-1,0,1,0};
int dy[4]={0,1,0,-1};
int n;
void dfs(int x,int y,vector<vector<int>>&grid, queue<pair<int,int>>&q,vector<vector<int>>&dp)
{
    dp[x][y]=1;
    q.push({x,y});
    for(int i=0;i<4;i++)
    {
        int nx=x+dx[i];
        int ny=y+dy[i];
        
        if(nx>=0 && ny>=0 && nx<n && ny<n && dp[nx][ny]==0 && grid[nx][ny]==1)
        {
            dfs(nx,ny,grid,q,dp);
        }
    }
}
class Solution 
{
public:
    int shortestBridge(vector<vector<int>>& grid) 
    {
        n=grid.size();
        queue<pair<int,int>>q;
        vector<vector<int>>dp(n,vector<int>(n));
        bool got=false;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==1)
                {
                    got=true;
                    dfs(i,j,grid,q,dp);
                    break;
                }
            }
            if(got)
            {
                break;
            }
        }
        int time=0;
        while(!q.empty())
        {
            int sz=q.size();
            while(sz--)
            {
                int x=q.front().first;
                int y=q.front().second;
                q.pop();
                for(int i=0;i<4;i++)
                {
                    int nx=x+dx[i];
                    int ny=y+dy[i];
                    
                    if(nx>=0 && ny>=0 && nx<n && ny<n && dp[nx][ny]==0)
                    {
                        dp[nx][ny]=1;
                        if(grid[nx][ny]==1)
                        {
                            return time;
                        }
                        q.push({nx,ny});
                    }
                }
            }
            time++;
        }
        return -1;
    }
};
