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

//Method-2 : Tabulation

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

//Method-3 : Space Optimization


class Solution 
{
public:
    int minPathSum(vector<vector<int>>&grid) 
    {
        int m=grid.size();
        int n=grid[0].size();
        vector<int>dp(n,0);
        int prev=0;
        for(int i=0;i<m;i++)
        {
            prev=0;
            for(int j=0;j<n;j++)
            {
                if(i==0 && j==0)
                {
                    prev=grid[0][0];
                    dp[j]=grid[0][0];
                }
                else if(i!=0 && j!=0)
                {
                    int a=grid[i][j]+dp[j];
                    int b=grid[i][j]+prev;
                    prev=min(a,b);
                    dp[j]=min(a,b);
                }
                else if(i==0)
                {
                    dp[j]=prev+grid[i][j];
                    prev=dp[j];
                }
                else if(j==0)
                {
                    dp[j]=dp[j]+grid[i][j];
                    prev=dp[j];
                }
            }
        }
        return prev;
    }
};


//Method-4 : 


class Solution 
{
public:
    int minPathSum(vector<vector<int>>& grid) 
    {
        int m=grid.size();
        int n=grid[0].size();
        int dp[m][n];
        int dx[2]={-1,0};
        int dy[2]={0,-1};
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                int temp=5000000;
                for(int k=0;k<2;k++)
                {
                    int nx=i+dx[k];
                    int ny=j+dy[k];
                    if(nx>=0 && ny>=0 && nx<m && ny<n)
                    {
                        temp=min(temp,dp[nx][ny]);
                    }
                }
                if(temp==5000000)
                    temp=0;
                dp[i][j]=grid[i][j]+temp;
            }
        }
        return dp[m-1][n-1];
    }
};
