int cherry(vector<vector<int>>& grid,int r1,int c1,int r2,vector<vector<vector<int>>>&dp)
{
    int n=grid.size();
    int c2=r1+c1-r2;
    if(r1>=n || c1>=n || r2>=n || c2>=n || grid[r1][c1]==-1 || grid[r2][c2]==-1)
        return INT_MIN;
    if(r1==n-1 && c1==n-1)
    {
        return grid[r1][c1];
    }
    if(dp[r1][c1][r2]==-1)
    {
        int temp=0;
        if(r1==r2 && c1==c2)
            temp=temp+grid[r1][c1];
        else
            temp=temp+grid[r1][c1]+grid[r2][c2];
        
        int a=cherry(grid,r1+1,c1,r2+1,dp);
        int b=cherry(grid,r1+1,c1,r2,dp);
        int c=cherry(grid,r1,c1+1,r2+1,dp);
        int d=cherry(grid,r1,c1+1,r2,dp);
        
        temp=temp+max(a,max(b,max(c,d)));
        
        dp[r1][c1][r2]=temp;
    }
    return dp[r1][c1][r2];
}
class Solution 
{
public:
    int cherryPickup(vector<vector<int>>& grid) 
    {
        int n=grid.size();
        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(n+1,vector<int>(n+1,-1)));
        return max(0,cherry(grid,0,0,0,dp));
    }
};
