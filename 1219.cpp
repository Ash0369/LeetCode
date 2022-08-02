int stored=0;
void gold(vector<vector<int>>&grid,int x_size,int y_size,int x,int y,int gold_path,vector<vector<int>>&visited)
{
    if(visited[x][y]==1)
    {
        return;
    }
    if(grid[x][y]==0)
    {
        return;
    }
    if(x>x_size || y>y_size || x<0 || y<0)
    {
        return;
    }
    visited[x][y]=1;
    gold_path=gold_path+grid[x][y];
    stored=max(stored,gold_path);
    if(x<x_size  && x>=0)
    {
        gold(grid,x_size,y_size,x+1,y,gold_path,visited);
    }
    if(x>0  && x<=x_size)
    {
        gold(grid,x_size,y_size,x-1,y,gold_path,visited);
    }
    if(y<y_size && y>=0)
    {
        gold(grid,x_size,y_size,x,y+1,gold_path,visited);
    }
    if(y>0 && y<=y_size)
    {
        gold(grid,x_size,y_size,x,y-1,gold_path,visited);
    }  
    visited[x][y]=0;
}
class Solution 
{
public:
    int getMaximumGold(vector<vector<int>>& grid) 
    {
        stored=0;
        int x_size=grid.size();
        int y_size=grid[0].size();
        vector<vector<int>>visited(x_size,vector<int>(y_size,0));
        for(int x=0;x<x_size;x++)
        {
            for(int y=0;y<y_size;y++)
            {
                gold(grid,x_size-1,y_size-1,x,y,0,visited);
            }
        }
        return stored;

    }
};
