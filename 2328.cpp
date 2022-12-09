int mod=1e9+7;
int dfs(vector<vector<int>>&grid,int x,int y,vector<vector<int>>&dp)
{
    if(dp[x][y]!=-1)
        return dp[x][y];
    int m=grid.size();
    int n=grid[0].size();
    int ans=1;
    int dx[4]={-1,0,1,0};
    int dy[4]={0,1,0,-1};
    for(int i=0;i<4;i++)
    {
        int nx=x+dx[i];
        int ny=y+dy[i];
        
        if(nx>=0 && ny>=0 && nx<m && ny<n && grid[nx][ny]>grid[x][y])
        {
            ans=(ans+dfs(grid,nx,ny,dp))%mod;
        }
    }
    dp[x][y]=ans;
    return ans;
}
class Solution 
{
public:
    int countPaths(vector<vector<int>>& grid) 
    {
        int m=grid.size();
        int n=grid[0].size();
        int ans=0;
        vector<vector<int>>dp(m,vector<int>(n,-1));
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                ans=(ans+dfs(grid,i,j,dp))%mod;
            }
        }
        return ans;
    }
};
