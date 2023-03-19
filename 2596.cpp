class Solution 
{
public:
    bool checkValidGrid(vector<vector<int>>& grid) 
    {
        int n=grid.size();
        int lastx=0;
        int lasty=0;
        if(grid[0][0]!=0)
        {
            return false;
        }
        for(int i=1;i<(n*n);i++)
        {
            bool got=false;
            for(int x=-2;x<=2 && got==false;x++)
            {
                for(int y=-2;y<=2;y++)
                {
                    if(abs(x)+abs(y)!=3)
                    {
                        continue;
                    }
                    int nx=lastx+x;
                    int ny=lasty+y;
                    if(nx>=0 && ny>=0 && nx<n && ny<n)
                    {
                         if(grid[nx][ny]==i)
                         {
                             lastx=nx;
                             lasty=ny;
                             got=true;
                             break;
                         }
                    }
                   
                }
            }
            if(got==false)
            {
                return false;
            }
        }
        return true;
    }
};
