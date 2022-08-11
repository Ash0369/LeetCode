//Method-1 : 

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


//Method-2 : 

class Solution 
{
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) 
    {
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();
        if(m==1 && n==1)
        {
            return abs(1-obstacleGrid[0][0]);
        }
        if(m==1 || n==1)
        {
            for(auto x:obstacleGrid)
            {
                for(auto y:x)
                {
                    if(y==1)
                    {
                        return 0;
                    }
                }
            }
            return 1;
        }
        vector<vector<int>>vec(m,vector<int>(n,-1));
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(obstacleGrid[i][j]==1)
                {
                    vec[i][j]=0;
                    continue;
                }
                if(i==0 && j==0)
                {
                    vec[i][j]=1;
                }
                if(i==0 && j!=0)
                {
                    vec[i][j]=vec[i][j-1];
                }
                else if(i!=0 && j==0)
                {
                    vec[i][j]=vec[i-1][j];
                }
                else if(i!=0 && j!=0)
                {
                    vec[i][j]=vec[i-1][j]+vec[i][j-1];
                }
            }
        }
        return vec[m-1][n-1];
    }
};
