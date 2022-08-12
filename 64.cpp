//Method-1 : Memoization

int path(vector<vector<int>>&grid,int x,int y,vector<vector<int>>&visited)
{
    if(x==0 && y==0)
    {
        return grid[x][y];
    }
    if(x<0 || y<0)
    {
        return 0;
    }
    if(visited[x][y]==-1)
    {
        int a=INT_MAX;
        int b=INT_MAX;
        if(x>0)
        {
            a=grid[x][y]+path(grid,x-1,y,visited);
        }
        if(y>0)
        {
            b=grid[x][y]+path(grid,x,y-1,visited);
        }
        visited[x][y]=min(a,b);
    }
    return visited[x][y];
}
class Solution 
{
public:
    int minPathSum(vector<vector<int>>&grid) 
    {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>>visited(m,vector<int>(n,-1));
        return path(grid,m-1,n-1,visited);
    }
};

//Method-2 : 

class Solution 
{
public:
    int minPathSum(vector<vector<int>>&grid) 
    {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>>dp(m,vector<int>(n,-1));
        dp[0][0]=grid[0][0];
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i==0 && j==0)
                {
                    dp[0][0]=grid[0][0];
                }
                else if(i!=0 && j!=0)
                {
                    int a=grid[i][j]+dp[i-1][j];
                    int b=grid[i][j]+dp[i][j-1];
                    dp[i][j]=min(a,b);
                }
                else if(i==0)
                {
                    dp[i][j]=grid[i][j]+dp[i][j-1];
                }
                else if(j==0)
                {
                    dp[i][j]=grid[i][j]+dp[i-1][j];
                }
            }
        }
        return dp[m-1][n-1];
    }
};

//Method-3 : 

