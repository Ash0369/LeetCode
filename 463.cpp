class Solution 
{
public:
    int islandPerimeter(vector<vector<int>>& grid) 
    {
        int row=grid.size();
        int col=grid[0].size();
        int dx[4]={-1,0,1,0};
        int dy[4]={0,1,0,-1};
        int ans=0;
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                if(grid[i][j]==1)
                {
                    for(int k=0;k<4;k++)
                    {
                        int nx=i+dx[k];
                        int ny=j+dy[k];
                        
                        if(nx>=0 && ny>=0 && nx<row && ny<col)
                        {
                            if(grid[nx][ny]==0)
                                ans++;
                        }
                        else
                            ans++;
                    }
                }
            }
        }
        return ans;
    }
};
