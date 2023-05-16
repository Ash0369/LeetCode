int dx[3]={-1,0,1};
int dy[3]={1,1,1};
int m,n;
int dfs(int x,int y,vector<vector<int>>&dp,vector<vector<int>>&grid)
{
    int mx=0;
    for(int i=0;i<3;i++)
    {
        int nx=x+dx[i];
        int ny=y+dy[i];
        
        if(nx>=0 && ny>=0 && nx<m && ny<n && grid[nx][ny]>grid[x][y])
        {
            if(dp[nx][ny]!=-1)
            {
                mx=max(mx,1+dp[nx][ny]);
                continue;
            }
            mx=max(mx,1+dfs(nx,ny,dp,grid));
        }
    }
    dp[x][y]=mx;
    return mx;
}
class Solution 
{
public:
    int maxMoves(vector<vector<int>>& grid) 
    {
        m=grid.size();
        n=grid[0].size();
        vector<vector<int>>dp(m,vector<int>(n,-1));
        int ans=0;
        for(int i=0;i<m;i++)
        {
            dp[i][0]==0;
            ans=max(ans,dfs(i,0,dp,grid));
        }
        return ans;
    }
};
