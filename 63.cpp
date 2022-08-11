int obstacle(vector<vector<int>>& obstacleGrid,int x,int y,vector<vector<int>>&dp)
{
    if(x<0 || y<0)
    {
        return 0;
    }
    else if(obstacleGrid[x][y]==1)
    {
        return 0;
    }
    else if(x==0 && y==0)
    {
        return 1;
    }
    if(dp[x][y]==-1)
    {
        int left=obstacle(obstacleGrid,x-1,y,dp);
        int up=obstacle(obstacleGrid,x,y-1,dp);
        dp[x][y]=left+up;
    }
    return dp[x][y];
}
class Solution 
{
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) 
    {
        int n=obstacleGrid.size();
        int m=obstacleGrid[0].size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return obstacle(obstacleGrid,n-1,m-1,dp);
    }
};
