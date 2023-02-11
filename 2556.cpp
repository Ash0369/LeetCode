bool dfs(vector<vector<int>>&grid,int x,int y)
{
    if(x==0 && y==0)
    {
        return true;
    }
    grid[x][y]=0;
    if(x-1>=0 && grid[x-1][y]==1)
    {
        if(dfs(grid,x-1,y))
            return true;
    }
    if(y-1>=0 && grid[x][y-1]==1)
    {
        if(dfs(grid,x,y-1))
            return true;
    }
    return false;
}
class Solution 
{
public:
    bool isPossibleToCutPath(vector<vector<int>>& grid) 
    {
        int m=grid.size();
        int n=grid[0].size();
        if(dfs(grid,m-1,n-1)==false)
            return true;
        if(dfs(grid,m-1,n-1)==false)
            return true;
        
        return false;
    }
};
