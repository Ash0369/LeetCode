int dx[4]={-1,0,1,0};
int dy[4]={0,1,0,-1};
bool dfs(vector<vector<char>>&grid,char c,int i,int j,vector<vector<int>>&dp,int x)
{
    dp[i][j]=x;//Storing at which point it is visited
    for(int k=0;k<4;k++)
    {
        int nx=i+dx[k];
        int ny=j+dy[k];
        
        if(nx>=0 && ny>=0 && nx<grid.size() && ny<grid[0].size() && grid[nx][ny]==c)
        {
            if(dp[nx][ny]!=-1)
            {
                if(abs(dp[nx][ny]-x)>=3)
                    return true;
                continue;
            }
            if(dfs(grid,c,nx,ny,dp,x+1))
               return true;
        }
    }
    return false;
}
class Solution 
{
public:
    bool containsCycle(vector<vector<char>>& grid) 
    {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(dp[i][j]==-1)
                {
                    if(dfs(grid,grid[i][j],i,j,dp,1))
                        return true;
                }
            }
        }
        return false;
    }
};
