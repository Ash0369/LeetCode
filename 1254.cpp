class Solution 
{
public:
    int closedIsland(vector<vector<int>>& grid) 
    {
        int m=grid.size();
        int n=grid[0].size();
        
        bool dp[m][n];
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                dp[i][j]=false;
            }
        }
        int dx[4]={-1,0,1,0};
        int dy[4]={0,1,0,-1};
        int ans=0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==0 && dp[i][j]==false)
                {
                    dp[i][j]=true;
                    queue<pair<int,int>>q;
                    q.push({i,j});
                    bool res=true;
                    while(!q.empty())
                    {
                        int x=q.front().first;
                        int y=q.front().second;
                        q.pop();
                        
                        for(int k=0;k<4;k++)
                        {
                            int nx=x+dx[k];
                            int ny=y+dy[k];
                            
                            if(nx<0 || ny<0 || nx>=m || ny>=n)
                            {
                                res=false;
                                continue;
                            
                            }
                            if(grid[nx][ny]==0 && dp[nx][ny]==false)
                            {
                                dp[nx][ny]=true;
                                q.push({nx,ny});
                            }
                            
                        }
                    }
                    if(res)
                        ans++;
                }
            }
        }
        return ans;
    }
};
