int dx[4]={-1,0,1,0};
int dy[4]={0,1,0,-1};
int dfs(int x,int y,vector<vector<int>>&grid,vector<vector<int>>&dp,int m,int n)
{
    dp[x][y]=1;
    int ans=0;
    for(int i=0;i<4;i++)
    {
        int nx=x+dx[i];
        int ny=y+dy[i];
        if(nx>=0 && ny>=0 && nx<m && ny<n && dp[nx][ny]==0 && grid[nx][ny]!=0)
        {
            ans+=dfs(nx,ny,grid,dp,m,n);
        }
    }
    
    return grid[x][y]+ans;
}
class Solution 
{
public:
    int findMaxFish(vector<vector<int>>& grid) 
    {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>>dp(m,vector<int>(n,0));
        int ans=0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]!=0 && dp[i][j]==0)
                {
                    int val=dfs(i,j,grid,dp,m,n);
                    ans=max(ans,val);
                }
            }
        }
        return ans;
    }
};
