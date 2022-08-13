int cp(vector<vector<int>>&grid,int i,int j1,int j2)
{
    if(j1<0 || j2<0 || j1>=grid[0].size() || j2>=grid[0].size())
    {
        return -1e8;
    }
    if(i==grid.size()-1)
    {
        if(j1==j2)
        {
            return grid[i][j1];
        }
        return grid[i][j1]+grid[i][j2];
    }

    
    int nxt_lvl=-1e8;
    for(int a=-1;a<=1;a++)
    {
        for(int b=-1;b<=1;b++)
        {
            int cherry=0;
            if(j1==j2)
            {
                cherry=grid[i][j1];
            }
            else
            {
                cherry=grid[i][j2]+grid[i][j1];
            }
            cherry=cherry+cp(grid,i+1,j1+a,j2+b);
            nxt_lvl=max(nxt_lvl,cherry);
        }
    }
    return nxt_lvl;

}
class Solution 
{
public:
    int cherryPickup(vector<vector<int>>& grid) 
    {
        return cp(grid,0,0,grid[0].size()-1);
    }
};
